#include "vectorinputdialog.h"
#include "ui_vectorinputdialog.h"

VectorInputDialog::VectorInputDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VectorInputDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

VectorInputDialog::~VectorInputDialog()
{
    delete ui;
}

std::string normalizeString(std::string);
double* strToDoubleArr(std::size_t, std::string);

void VectorInputDialog::on_vectorinput_textChanged()
{

}

void VectorInputDialog::on_pushButton_released()
{

    // name[size]{a1, a2, a3, ..., asize}\n
    std::string line =
        ui->vectorinput->toPlainText().toUtf8().constData();

    std::size_t
        indexOpenSB = line.find('['),
        indexCloseSB = line.find(']'),
        indexOpenCB = line.find('{'),
        indexCloseCB = line.find('}');

    bool bracesExist = indexOpenSB != std::string::npos &&
                       indexCloseSB != std::string::npos &&
                       indexOpenCB != std::string::npos &&
                       indexCloseCB != std::string::npos;

    bool validbraces = indexOpenSB < indexCloseSB &&
                       indexOpenCB < indexCloseCB;

    bool bracesArentMixed = indexCloseSB < indexOpenCB;

    char counters = 0;
    for (auto& i : line)
    {
        switch(i)
        {
        case '[':
            if (0b0001 & counters) goto extra_braces;
            else counters = counters | 0b0001;
            break;
        case ']':
            if (0b0010 & counters) goto extra_braces;
            else counters = counters | 0b0010;
            break;
        case '{':
            if (0b0100 & counters) goto extra_braces;
            else counters = counters | 0b0100;
            break;
        case '}':
            if (0b1000 & counters) goto extra_braces;
            else counters = counters | 0b1000;
        }

        if (false)
        {
        extra_braces:
            labelText = "extra braces\n";
            goto bad_sentence;
        }
    }

    if (!bracesExist)
    {
        labelText = "check for braces\n";
    }
    else if (!validbraces)
    {
        labelText = "closed brace before open one\n";
    }
    else if (!bracesArentMixed)
    {
        labelText = "Curve braced after Square\n";
    }

    if (!bracesExist || !validbraces || !bracesArentMixed)
    {
        bad_sentence:
        ui->status->setText(labelText);
        legalVector = false;
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(legalVector);
        return;
    }

    std::string name = line.substr(0, indexOpenSB);
    std::string sizeStr = std::string(line.begin() + indexOpenSB + 1,
                                      line.begin() + indexCloseSB);
    std::string elementsStr = std::string(line.begin() + indexOpenCB + 1,
                                          line.begin() + indexCloseCB);

    size_t sizeVec;
    double* elementsArr;

    try
    {
        name = normalizeString(name);
        sizeVec = atof(sizeStr.c_str());
        elementsArr = strToDoubleArr(sizeVec, elementsStr);
    }
    catch(std::exception e)
    {
        labelText = QString::fromUtf8(e.what(), strlen(e.what()));
        ui->status->setText(labelText);
        legalVector = false;
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(legalVector);
        return;
    }

    result = new VectorData(name, MathVector<double>(sizeVec, elementsArr));
    ui->status->setText(QString("good"));

    legalVector = true;
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(legalVector);
}

std::string normalizeString(std::string str)
{
    std::string normalStr = "";

    bool wasSpace = false,
        wasName = false;

    for (auto& i: str)
    {
        switch (i)
        {
        case ' ':
        case '\t':
            if (!wasSpace) wasSpace = true;
            else if (wasName) throw std::runtime_error("bad name");
            break;
        case '\n':
            throw std::runtime_error("endOfLine");
            break;
        default:
            normalStr += i;
            wasName = true;
        }
    }

    return normalStr;
}

double* strToDoubleArr(std::size_t arrSize, std::string str)
{
    double* mas = new double[arrSize];
    std::size_t pointer_to_cell = 0;
    std::string elementBuff = "";

    enum
    {
        NONE = 0,
        READ = 1,
        WROTE = 2
    } state = NONE;

    for (auto& i : str)
    {
        switch(i)
        {
        case ',':
            if (pointer_to_cell >= arrSize) throw std::runtime_error("item out of array range");
            mas[pointer_to_cell++] = atof(elementBuff.c_str());
            elementBuff = "";
            state = NONE;
            break;
        case ' ':
            if (state == READ)
                state = WROTE;

            break;
        default:
            if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
                throw std::runtime_error("not a num\n");
            if (state == WROTE) throw std::runtime_error("bad array\n");
            state = READ;
            elementBuff += i;
        }
    }

    if (pointer_to_cell >= arrSize) throw std::runtime_error("item out of array range");
    mas[pointer_to_cell] = atof(elementBuff.c_str());
    return mas;
}

void VectorInputDialog::on_buttonBox_accepted()
{

}

