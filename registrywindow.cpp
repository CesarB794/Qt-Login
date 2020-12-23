#include "registrywindow.h"
#include "ui_registrywindow.h"

RegistryWindow::RegistryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistryWindow)
{
    ui->setupUi(this);
}

RegistryWindow::~RegistryWindow()
{
    delete ui;
}

void RegistryWindow::on_SingInButton_clicked()
{

}

void RegistryWindow::on_CancelButton_clicked()
{

}
