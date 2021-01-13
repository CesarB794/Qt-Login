#include "user.h"

User::User()
{

}

void User::setName(QString a)
{
    this->Name=a;
}

QString User::getName()
{
    return this->Name;
}

void User::setLastName(QString a)
{
    this->LastName=a;
}

QString User::getLastName()
{
    return this->LastName;
}

void User::setUserName(QString a)
{
    this->UserName=a;
}

QString User::getUserName()
{
    return this->UserName;
}

void User::setPasswd(QString a)
{
    this->Passwd=a;
}

QString User::getPasswd()
{
    return this->Passwd;
}

User::~User()
{

}
