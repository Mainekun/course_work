#ifndef VECTORINPUTDIALOG_H
#define VECTORINPUTDIALOG_H

#include <QDialog>
#include <QString>
#include "vectordata.h"

namespace Ui {
class VectorInputDialog;
}

class VectorInputDialog : public QDialog
{
    Q_OBJECT
    bool legalVector = false;
    QString labelText = "";
    VectorData* result;

public:
    explicit VectorInputDialog(QWidget *parent = nullptr);
    ~VectorInputDialog();

private slots:
    void on_vectorinput_textChanged();

    void on_pushButton_released();

    void on_buttonBox_accepted();

private:
    Ui::VectorInputDialog *ui;
};

#endif // VECTORINPUTDIALOG_H
