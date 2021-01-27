#include "user.h"
#include <QSqlError>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include "registrywindow.h"
#include "ui_registrywindow.h"
#include <QSqlDatabase>

RegistryWindow::RegistryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistryWindow)
{
    ui->setupUi(this);
    QSqlDatabase *db;
    db=QSqlDatabase::addDatabase("QSLQLITE");
    db->setDatabaseName(path);
    if(db->open())
    {
        qDebug()<<"Database Connection Succesfully.";
    }
    else
    {
        qDebug()<<"Database Connection Failed.";
    }

}

RegistryWindow::~RegistryWindow()
{
    delete ui;
}

bool RegistryWindow::Register(const QString &name, const QString &lastName, const QString &user, const QString &passwd)
{
    bool Registred;
    qDebug()<<"prepare: "<<sql.prepare("INSERT INTO Users(name, lastName, userName, password) VALUES(?, ?, ?, ?);");
    sql.addBindValue(name);
    sql.addBindValue(lastName);
    sql.addBindValue(user);
    sql.addBindValue(passwd);
    if(sql.exec())
    {
       Registred=true;
       qDebug()<<"Query executed sucessfully";
    }
    else
    {
        Registred=false;
        qDebug()<<"Failed to execute query: Error"<<sql.lastError();
    }
    return Registred;
}



void RegistryWindow::on_SingInButton_clicked()
{
    User u1=User();
    QMessageBox M;
    this->ui->NameText->setFocus();
    QString name=this->ui->NameText->text();
    QString lastname=this->ui->LastNameText->text();
    QString user=this->ui->UserText->text();
    QString passwd=this->ui->PasswdText->text();
    QString check_passwd=this->ui->AuxPasswdText->text();
    if(passwd==check_passwd)
    {
        u1.setName(name);
        u1.setLastName(lastname);
        u1.setUserName(user);
        u1.setPasswd(passwd);
        if(Register(u1.getName(), u1.getLastName(), u1.getUserName(), u1.getPasswd()))
        {
           M.setText("Registred sucessfully.");
        }
        else
        {
            M.setText("Sing Up failed.");
        }
        this->close();
    }
    else
    {
        M.setWindowTitle("Registry Error");
        M.setText("Passwords not match! ");
        this->ui->NameText->clear();
        this->ui->LastNameText->clear();
        this->ui->UserText->clear();
        this->ui->PasswdText->clear();
        this->ui->AuxPasswdText->clear();
        this->ui->NameText->setFocus();
    }
}

void RegistryWindow::on_CancelButton_clicked()
{
    this->close();
}
