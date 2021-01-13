#ifndef USER_H
#define USER_H
#include <QString>
class User
{
private:
    QString Name;
    QString LastName;
    QString UserName;
    QString Passwd;
public:
    User();
    void setName(QString);
    QString getName();
    void setLastName(QString);
    QString getLastName();
    void setUserName(QString);
    QString getUserName();
    void setPasswd(QString);
    QString getPasswd();
    ~User();
};

#endif // USER_H
