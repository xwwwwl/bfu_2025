#include "set_avatar_photo.h"
#include "filehandler.h"
#include "QJsonObject"

QString SetAvatarPhoto::execute(User* user, const QString& photoPath){

    FileHandler file_handler;
    QVector<QVariant> user_info= file_handler.find_user(user->get_login(),user->get_filepath());
    if (!user_info.isEmpty()){
        QJsonObject user_json=user_info[0].toJsonObject();
        int lineIndex= user_info[1].toInt();
        QStringList allLines= user_info[2].toStringList();
        for (int i=0;i<4;i++){
            if (user_json[QString("photo_%1").arg(i+1)].toString() == photoPath){
                user_json["avatar"] = QString("photo_%1").arg(i+1);
                allLines[lineIndex] = QString(QJsonDocument(user_json).toJson(QJsonDocument::Compact));
                QString error_write_file = file_handler.write_user_info(allLines,user->get_filepath());
                return error_write_file;
            }
        }


    }

    return "не удалось найти данного юзера";

}
