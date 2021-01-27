#include "loginwindow.h"
#include "welcome.h"
#include <QMessageBox>
#include "ui_loginwindow.h"
#include <QSqlError>
#include <QDebug>

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

bool LoginWindow::Login(const QString &User, const QString &Passwd)
{
    bool Loged=false;
    sql.prepare("SELECT FROM Users WHERE userName=? AND password=?;");
    sql.addBindValue(User);
    sql.addBindValue(Passwd);
    if(sql.exec())
    {
        if(sql.next())
        {
           Loged=true;
        }
        else
        {
            Loged=false;
        }
    }
    else
    {
        qDebug()<<"Failed to exectute query:"<<sql.lastError();
    }
    return Loged;
}

void LoginWindow::on_AcceptButton_clicked()
{
    QMessageBox M;
    this->ui->LoginUserBox->setFocus();
    if(Login(this->ui->LoginUserBox->text(), this->ui->LoginPasswdBox->text())==true)
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
