#include "user.h"
#include "database.h"
#include <QMessageBox>
#include <QString>
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
    User u1=User();
    Database db=Database();
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
        if(db.Register(u1.getName(), u1.getLastName(), u1.getUserName(), u1.getPasswd())==true)
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
