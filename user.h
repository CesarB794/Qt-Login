#ifndef USER_H
#define USER_H
#include <string>
class User
{
private:
    std::string Name;
    std::string LastName;
    std::string UserName;
    std::string Passwd;
public:
    User();
    void setName(std::string);
    std::string getName();
    void setLastName(std::string);
    std::string getLastName();
    void setUserName(std::string);
    std::string getUserName();
    void setPasswd(std::string);
    std::string getPasswd();
    ~User();
};

#endif // USER_H
