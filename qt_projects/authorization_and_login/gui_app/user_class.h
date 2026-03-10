#ifndef USER_CLASS_H
#define USER_CLASS_H

#include <QDir>


class User{
private:
    QString login_;
    QString password_;
    QString filepath_;
    int id_;
public:
    User(QString login,QString password,QString filepath);
    bool add_user();
    bool user_check();
    bool login_user_check();
    int get_id();
    QString get_login();
    QString get_filepath();
    QString get_password();
};


int getLastId(const QString& filePath);
bool password_check(QString password, QString alphabet);


#endif // USER_CLASS_H
