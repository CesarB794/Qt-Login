#include "user.h"

User::User()
{

}

void User::setName(std::string a)
{
    this->Name=a;
}

std::string User::getName()
{
    return this->Name;
}

void User::setLastName(std::string a)
{
    this->LastName=a;
}

std::string User::getLastName()
{
    return this->LastName;
}

void User::setUserName(std::string a)
{
    this->UserName=a;
}

std::string User::getUserName()
{
    return this->UserName;
}

void User::setPasswd(std::string a)
{
    this->Passwd=a;
}

std::string User::getPasswd()
{
    return this->Passwd;
}

User::~User()
{

}
