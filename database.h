#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <QString>
#include <QSqlDatabase>
class Database
{
private:
    QString path="user.db";
    QSqlDatabase db;
public:
    Database();
    bool Register(const QString &, const QString &, const QString &, const QString &);
    bool Login(const QString &, const QString &);
    ~Database();
};

#endif // DATABASE_H
