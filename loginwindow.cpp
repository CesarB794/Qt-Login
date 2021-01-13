#include "loginwindow.h"
#include "welcome.h"
#include <QMessageBox>
#include "database.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_CancelButton_clicked()
{
   this->close();
}

void LoginWindow::on_AcceptButton_clicked()
{
    Database db=Database();
    QMessageBox M;
    this->ui->LoginUserBox->setFocus();
    if(db.Login(this->ui->LoginUserBox->text(), this->ui->LoginPasswdBox->text())==true)
    {
       Welcome w;
       w.show();
    }
    else
    {
        M.setWindowTitle("Login Failed");
        M.setText("User or password are incorrect.");
    }
}
