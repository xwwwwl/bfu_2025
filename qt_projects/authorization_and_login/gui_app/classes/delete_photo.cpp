#include "delete_photo.h"
#include <QJsonObject>
DeletePhoto::DeletePhoto(PhotoFileHandler photo_file_handler, UserFileHandler user_file_handler) : photo_file_handler_(photo_file_handler), user_file_handler_(user_file_handler){}

QString DeletePhoto::execute(QString login, const QString& photoPath)
{
    QVector<QVariant> user_info= user_file_handler_.find_user(login);
    if (!user_info.isEmpty()){
        QJsonObject user_json=user_info[0].toJsonObject();
        int lineIndex= user_info[1].toInt();
        QStringList allLines= user_info[2].toStringList();
        for (int i=0;i<4;i++){
            if (user_json[QString("photo_%1").arg(i+1)].toString() == photoPath){
                if (photo_file_handler_.DeletePhoto(photoPath) && photo_file_handler_.DeleteAllEmptyFolder(photoPath)){
                    user_json[QString("photo_%1").arg(i+1)] = "plug";
                    allLines[lineIndex] = QString(QJsonDocument(user_json).toJson(QJsonDocument::Compact));
                    QString error_write_file =user_file_handler_.write_user_info(allLines);
                    return error_write_file;
                }

            }
        }
    }



    return "у вас нет фото, чтобы его удалить";

}
