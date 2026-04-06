#include "upload_photo.h"
#include <QString>
#include "QJsonObject"
#include "QCoreApplication"
#include "func.h"
#include "logger.hpp"
#include <QDateTime>
#include <QImageReader>

UploadPhoto::UploadPhoto(PhotoFileHandler photo_file_handler,UserFileHandler user_file_handler) : photo_file_handler_(photo_file_handler), user_file_handler_(user_file_handler){}

QString UploadPhoto::execute(QString login, const QString& photoPath)
{
    QString folder_filepath = find_path(QCoreApplication::applicationFilePath(),"photos");
    QVector<QVariant> user_info= user_file_handler_.find_user(login);
    bool userFound = false;
    bool photoAdded = false;
    if (!user_info.isEmpty()){
        userFound = true;

        QJsonObject user_Json = user_info[0].toJsonObject();
        int lineIndex= user_info[1].toInt();
        QStringList allLines= user_info[2].toStringList();
        QString photo_1 = user_Json["photo_1"].toString();
        QString photo_2 = user_Json["photo_2"].toString();
        QString photo_3 = user_Json["photo_3"].toString();
        QString photo_4 = user_Json["photo_4"].toString();
        QVector<QString> photos = {photo_1, photo_2, photo_3, photo_4};
        if (!photos.contains("plug")) {
            LOG_ERROR("Пользователь может добавить только 4 изображения");
            return "Пользователь может добавить не более 4 изображений";
        }
        for (int i = 0; i < photos.size(); i++) {
            if (photos[i] == "plug") {

                QDateTime now = QDateTime::currentDateTime();
                QString now_milisec = QString::number(now.toMSecsSinceEpoch());
                QString time_upload_photo = now.toString("yyyyMMdd");
                QString year_upload_photo = time_upload_photo.left(4);
                QString mounth_upload_photo = time_upload_photo.mid(4,2);
                QString day_upload_photo = time_upload_photo.mid(6,2);

                QString user_folder = folder_filepath + "/"+ login;
                QString user_year_folder =user_folder + "/"+ year_upload_photo;
                QString user_mounth_folder = user_year_folder + "/"+ mounth_upload_photo;
                QString user_day_folder = user_mounth_folder + "/"+ day_upload_photo;

                photo_file_handler_.create_folder(user_folder);
                photo_file_handler_.create_folder(user_year_folder);
                photo_file_handler_.create_folder(user_mounth_folder);
                photo_file_handler_.create_folder(user_day_folder);

                // QImageReader photo_reader(photoPath);
                // QByteArray photo_format = photo_reader.format();

                // QString newPhotoPath = user_day_folder+"/"+now_milisec+"."+QString(photo_format);
                QString newPhotoPath = user_day_folder+"/"+now_milisec+".png";
                LOG_INFO(newPhotoPath);
                if (photo_file_handler_.CopyPhoto(photoPath,newPhotoPath)){
                    user_Json[QString("photo_%1").arg(i + 1)] = newPhotoPath;
                    photoAdded = true;
                    allLines[lineIndex] = QString(QJsonDocument(user_Json).toJson(QJsonDocument::Compact));
                    LOG_INFO(QString("Фото добавлено на позицию %1: %2")
                                 .arg(i + 1).arg(newPhotoPath));
                    break;
                }
                else{
                    return "не удалось скопировать фото";
                }
            }
        }

        if (!userFound) {
            LOG_INFO("Пользователь с логином: " + login + " не найдено");
            return "Пользователь с логином: " + login + " не найдено";
        }
        if (!photoAdded) {
            LOG_ERROR("Не удалось добавить фото");
            return "Не удалось добавить фото";
        }
        QString error_write_file = user_file_handler_.write_user_info(allLines);
        return error_write_file;

    }
    else{
        return "Не удалось загрузить фото";
    }
}
