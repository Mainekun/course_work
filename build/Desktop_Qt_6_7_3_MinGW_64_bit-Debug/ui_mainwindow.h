/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *equasionField;
    QPlainTextEdit *vectorIO;
    QPlainTextEdit *plainTextEdit;
    QPushButton *addVectorBtn;
    QPushButton *removeBtn;
    QPushButton *editBtn;
    QPushButton *solveBtn;
    QListView *VectorListView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 280);
        MainWindow->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        equasionField = new QPlainTextEdit(centralwidget);
        equasionField->setObjectName("equasionField");
        equasionField->setGeometry(QRect(260, 80, 331, 71));
        vectorIO = new QPlainTextEdit(centralwidget);
        vectorIO->setObjectName("vectorIO");
        vectorIO->setGeometry(QRect(260, 10, 331, 61));
        vectorIO->setPlaceholderText(QString::fromUtf8("\320\227\320\264\320\265\321\201\321\214 \320\262\321\213\320\262\320\276\320\264\321\217\321\202\321\201\321\217(\320\262\320\262\320\276\320\264\321\217\321\202\321\201\321\217) \320\262\320\265\320\272\321\202\320\276\321\200\321\213"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(260, 160, 331, 61));
        addVectorBtn = new QPushButton(centralwidget);
        addVectorBtn->setObjectName("addVectorBtn");
        addVectorBtn->setGeometry(QRect(10, 10, 91, 18));
        removeBtn = new QPushButton(centralwidget);
        removeBtn->setObjectName("removeBtn");
        removeBtn->setGeometry(QRect(10, 40, 91, 18));
        editBtn = new QPushButton(centralwidget);
        editBtn->setObjectName("editBtn");
        editBtn->setGeometry(QRect(10, 70, 91, 18));
        solveBtn = new QPushButton(centralwidget);
        solveBtn->setObjectName("solveBtn");
        solveBtn->setGeometry(QRect(10, 100, 91, 18));
        VectorListView = new QListView(centralwidget);
        VectorListView->setObjectName("VectorListView");
        VectorListView->setGeometry(QRect(110, 10, 141, 211));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "VectorCalculator", nullptr));
        addVectorBtn->setText(QCoreApplication::translate("MainWindow", "Add Vector", nullptr));
        removeBtn->setText(QCoreApplication::translate("MainWindow", "Remove Vector", nullptr));
        editBtn->setText(QCoreApplication::translate("MainWindow", "Edit Vector", nullptr));
        solveBtn->setText(QCoreApplication::translate("MainWindow", "Solve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
