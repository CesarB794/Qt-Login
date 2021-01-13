#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "registrywindow.h"
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
    LoginWindow *lw=new LoginWindow();
    lw->show();
}

void MainWindow::on_RegistryButton_clicked()
{
    RegistryWindow *rw=new RegistryWindow();
    rw->show();
}

void MainWindow::on_ExitButton_clicked()
{
   this->close();
}
