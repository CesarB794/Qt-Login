#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_LoginButton_clicked()
{

}

void MainWindow::on_RegistryButton_clicked()
{

}

void MainWindow::on_ExitButton_clicked()
{
   this->close();
}
