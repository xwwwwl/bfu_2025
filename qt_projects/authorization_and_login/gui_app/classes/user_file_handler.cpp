#include "user_file_handler.h"
#include <QJsonObject>

UserFileHandler::UserFileHandler(User user)
    : user_(user){}

QString UserFileHandler::get_path_to_user_avatar(){
    QVector<QVariant> user_info= find_user(user_.get_login(),user_.get_filepath());
    if (!user_info.isEmpty()){
        QJsonObject user_Json = user_info[0].toJsonObject();
        QString path_to_user_avatar = user_Json[user_Json["avatar"].toString()].toString();
        return path_to_user_avatar;
    }
    return "0";
}


QVector<QString> UserFileHandler::get_vector_to_user_photo(){
    QVector<QVariant> user_info= find_user(user_.get_login(),user_.get_filepath());
    if (!user_info.isEmpty()){
        QJsonObject user_Json=user_info[0].toJsonObject();
        QVector<QString> user_photo = {user_Json["photo_1"].toString(),user_Json["photo_2"].toString(),user_Json["photo_3"].toString(),user_Json["photo_4"].toString()};
        return user_photo;
    }
    QVector<QString> user_photo = {"","","",""};
    return user_photo;
}
