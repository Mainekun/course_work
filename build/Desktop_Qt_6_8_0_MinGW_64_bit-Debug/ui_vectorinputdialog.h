/********************************************************************************
** Form generated from reading UI file 'vectorinputdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VECTORINPUTDIALOG_H
#define UI_VECTORINPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_VectorInputDialog
{
public:
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *vectorinput;
    QLabel *status;
    QPushButton *pushButton;

    void setupUi(QDialog *VectorInputDialog)
    {
        if (VectorInputDialog->objectName().isEmpty())
            VectorInputDialog->setObjectName("VectorInputDialog");
        VectorInputDialog->resize(361, 102);
        buttonBox = new QDialogButtonBox(VectorInputDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 70, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Ok);
        buttonBox->setCenterButtons(false);
        vectorinput = new QPlainTextEdit(VectorInputDialog);
        vectorinput->setObjectName("vectorinput");
        vectorinput->setGeometry(QRect(10, 10, 341, 41));
        status = new QLabel(VectorInputDialog);
        status->setObjectName("status");
        status->setGeometry(QRect(10, 55, 341, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        status->setFont(font);
        pushButton = new QPushButton(VectorInputDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(9, 74, 80, 24));

        retranslateUi(VectorInputDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, VectorInputDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, VectorInputDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(VectorInputDialog);
    } // setupUi

    void retranslateUi(QDialog *VectorInputDialog)
    {
        VectorInputDialog->setWindowTitle(QCoreApplication::translate("VectorInputDialog", "Dialog", nullptr));
        status->setText(QString());
        pushButton->setText(QCoreApplication::translate("VectorInputDialog", "Check", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VectorInputDialog: public Ui_VectorInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VECTORINPUTDIALOG_H
