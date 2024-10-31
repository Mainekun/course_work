#ifndef VECTORINPUTDIALOG_H
#define VECTORINPUTDIALOG_H

#include <QDialog>

namespace Ui {
class VectorInputDialog;
}

class VectorInputDialog : public QDialog
{
    Q_OBJECT
    bool legalVector = false;

public:
    explicit VectorInputDialog(QWidget *parent = nullptr);
    ~VectorInputDialog();

private slots:
    void on_vectorinput_textChanged();

private:
    Ui::VectorInputDialog *ui;
};

#endif // VECTORINPUTDIALOG_H
