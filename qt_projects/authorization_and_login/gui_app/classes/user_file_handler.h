#ifndef USER_FILE_HANDLER_H
#define USER_FILE_HANDLER_H
#include "filehandler.h"
#include <QJsonObject>

class UserFileHandler : public FileHandler
{
private:
    QString filepath_;
public:
    UserFileHandler(QString filepath);
    bool add_user(QString login, QString password);
    bool user_check(QString login, QString password, QJsonObject user_json);
    QString get_filepath();
    QVector<QVariant> find_user(QString login);
    QString write_user_info(QStringList All_Lines);
    QString get_path_to_user_avatar(QJsonObject user_Json);
    QVector<QString> get_vector_to_user_photo(QJsonObject user_Json);




};

#endif // USER_FILE_HANDLER_H
