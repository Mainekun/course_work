#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vectorinputdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addVectorBtn_released()
{
    VectorInputDialog* ioDialog = new VectorInputDialog(this);

    int code = ioDialog->exec();

    if(code == QDialog::Accepted)
        ui->statusbar->showMessage(QString::fromUtf8("accepted", 8));
    else
        ui->statusbar->showMessage(QString::fromUtf8("rejected", 8));
    delete ioDialog;
}


void MainWindow::on_editBtn_released()
{

}

