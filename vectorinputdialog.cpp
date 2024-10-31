#include "vectorinputdialog.h"
#include "ui_vectorinputdialog.h"

VectorInputDialog::VectorInputDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VectorInputDialog)
{
    ui->setupUi(this);
}

VectorInputDialog::~VectorInputDialog()
{
    delete ui;
}

struct VectorData {
    std::string name;
    unsigned int size;
    double const * elements;
};

void ReadNameAndSize(std::string& str, std::string& name, unsigned int& size)
{
    name = "";
    std::string sizeStr = "";

    int parantesses = 0;
    for (auto i : str)
    {
        switch (i)
        {
        case '[':
            parantesses--;
            break;
        case ']':
            parantesses++;
            break;
        }
        if (parantesses > 0) throw std::runtime_error("syntax error: parantesses");
    }
    if (parantesses != 0) throw std::runtime_error("syntax error: parantesses");

    int status = -1;
    const int NAME_STARTED = 0;
    const int NAME_ENTERED = 1;
    const int SIZE_STARTED = 2;
    const int SIZE_ENTERED = 3;

    for (auto ch : str)
    {
        switch(ch)
        {
        case ' ':
            switch (status)
            {
            case -1:
                break;

            case NAME_STARTED:
                status = NAME_ENTERED;
                break;
            }

            if (status == NAME_STARTED) status = NAME_ENTERED;
            else                        status = NAME_STARTED;
            break;

        case '[':
            if (status == NAME_ENTERED || status == NAME_STARTED) status = SIZE_STARTED;
            else throw std::runtime_error("syntax error: extra [");
            break;

        case ']':
            if (status == SIZE_STARTED) status = SIZE_ENTERED;
            else throw std::runtime_error("syntax error: extra ]");
            break;

        default:
            if (status == -1) status = NAME_STARTED;

            if (status < NAME_ENTERED)       name += ch;
            else if (status == SIZE_STARTED) sizeStr += ch;
            else throw std::runtime_error("syntax error: letters");

            break;
        }
    }

    size = atoi(sizeStr.c_str());
}

void ReadElements(std::string& str, double * elementsPtr)
{

}

void VectorInputDialog::on_vectorinput_textChanged()
{
    QString enteredVector = ui->vectorinput->toPlainText();
    // "VectorName"("Size"): ( A1, A2, ..., A"Size" )

    std::string vectorName;
    unsigned int vectorSize;
    double * elements;

    unsigned int nameEnding = enteredVector.indexOf(':');
    std::string stdString = enteredVector.toStdString();

    std::string mainInfo = std::string(stdString.begin(), stdString.begin() + nameEnding);
    std::string elementsInfo = std::string(stdString.begin() + nameEnding, stdString.end());

    ReadNameAndSize(mainInfo, vectorName, vectorSize);
    ReadElements(elementsInfo, elements);

}

