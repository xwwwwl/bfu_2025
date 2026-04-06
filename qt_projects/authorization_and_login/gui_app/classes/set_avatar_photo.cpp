#include "set_avatar_photo.h"
#include "QJsonObject"
SetAvatarPhoto::SetAvatarPhoto(UserFileHandler user_file_handler) : user_file_handler_(user_file_handler){}

QString SetAvatarPhoto::execute(QString login, const QString& photoPath){

    QVector<QVariant> user_info= user_file_handler_.find_user(login);
    if (!user_info.isEmpty()){
        QJsonObject user_json=user_info[0].toJsonObject();
        int lineIndex= user_info[1].toInt();
        QStringList allLines= user_info[2].toStringList();
        for (int i=0;i<4;i++){
            if (user_json[QString("photo_%1").arg(i+1)].toString() == photoPath){
                user_json["avatar"] = QString("photo_%1").arg(i+1);
                allLines[lineIndex] = QString(QJsonDocument(user_json).toJson(QJsonDocument::Compact));
                QString error_write_file = user_file_handler_.write_user_info(allLines);
                return error_write_file;
            }
        }


    }

    return "не удалось найти данного юзера";

}
