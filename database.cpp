#include "database.h"
#include <iostream>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
Database::Database()
{
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    if(!db.open())
    {
       qDebug()<<"Error: connection with database failed";
    }
    else
    {
        qDebug()<<"Database: connection succesful";
    }
}

bool Database::Register(const QString &name, const QString &lastName, const QString &user, const QString &passwd)
{
    QSqlQuery sql;
    qDebug()<<"prepare: "<<sql.prepare("INSERT INTO Users(name, lastName, userName, password) VALUES(:name, :lastname, :user, :passwd)");
    sql.bindValue(":name", name);
    sql.bindValue(":lastname", lastName);
    sql.bindValue(":user", user);
    sql.bindValue(":passwd", passwd);
    if(sql.exec())
    {
       return true;
       qDebug()<<"Query executed sucessfully";
    }
    else
    {
        return false;
        qDebug()<<"Failed to execute query: Error"<<sql.lastError();
    }
}

bool Database::Login(const QString &User, const QString &Passwd)
{
    QSqlQuery sql;
    bool Loged=false;
    sql.prepare("SELECT * FROM Users WHERE userName=(:name) AND password=(:passwd)");
    sql.bindValue(":userName", User);
    sql.bindValue(":password", Passwd);
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

Database::~Database()
{
    db.close();
}
