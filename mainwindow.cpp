#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vectorinputdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->VectorListView->setModel(&vec_mod);
}

MainWindow::~MainWindow()
{
    delete ui;
}
