#include "photooperation.h"
#include "filehandler.h"
#include "logger.hpp"
#include "user_class.h"
#include <QJsonObject>
#include <QCoreApplication>
#include "func.h"

QString UploadPhoto::execute(User* user, const QString& photoPath)
{
    QString folder_filepath = find_path(QCoreApplication::applicationFilePath(),"photos");
    FileHandler file_handler;
    QVector<QVariant> user_info= file_handler.find_user(user->get_login(),user->get_filepath());
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

                QFileInfo photoInfo(photoPath);
                QString newFileName = photoInfo.fileName();
                QString newPhotoPath = folder_filepath + "/" + user->get_login()+newFileName;
                if (photo_1 == newPhotoPath or photo_2 == newPhotoPath or photo_3 == newPhotoPath or photo_4 == newPhotoPath){
                    LOG_ERROR("нелья добавлять одинаковые кариинки");
                    return "нелья добавлять одинаковые изображения";
                }
                if (!QFile::copy(photoPath, newPhotoPath)) {
                    LOG_ERROR("Не удалось скопировать фото: " + photoPath);
                    return "Не удалось скопировать фото: " + photoPath;
                }
                user_Json[QString("photo_%1").arg(i + 1)] = newPhotoPath;
                photoAdded = true;
                allLines[lineIndex] = QString(QJsonDocument(user_Json).toJson(QJsonDocument::Compact));
                LOG_INFO(QString("Фото добавлено на позицию %1: %2")
                             .arg(i + 1).arg(newFileName));
                break;
            }
        }

        if (!userFound) {
            LOG_INFO("Пользователь с логином: " + user->get_login() + " не найдено");
            return "Пользователь с логином: " + user->get_login() + " не найдено";
        }
        if (!photoAdded) {
            LOG_ERROR("Не удалось добавить фото");
            return "Не удалось добавить фото";
        }
        QString error_write_file = file_handler.write_user_info(allLines,user->get_filepath());
        return error_write_file;

    }
    else{
        return "Не удалось загрузить фото";
    }
}

QString DeletePhoto::execute(User* user, const QString& photoPath)
{
    FileHandler file_handler;
    QVector<QVariant> user_info= file_handler.find_user(user->get_login(),user->get_filepath());
    if (!user_info.isEmpty()){
        QJsonObject user_json=user_info[0].toJsonObject();
        int lineIndex= user_info[1].toInt();
        QStringList allLines= user_info[2].toStringList();
        for (int i=0;i<4;i++){
            if (user_json[QString("photo_%1").arg(i+1)].toString() == photoPath){
                QFile delete_file(user_json[QString("photo_%1").arg(i+1)].toString());
                if (delete_file.exists()) {
                    if (delete_file.remove()) {
                        LOG_INFO("Фото успешно удалено");

                    } else {
                        LOG_INFO("Ошибка при удалении фото");
                        return "Ошибка при удалении фото:";
                    }
                } else {
                    LOG_INFO("Файл не существует");
                    return "Файл не существует";
                }
                user_json[QString("photo_%1").arg(i+1)] = "plug";
                allLines[lineIndex] = QString(QJsonDocument(user_json).toJson(QJsonDocument::Compact));
                QString error_write_file =file_handler.write_user_info(allLines,user->get_filepath());
                return error_write_file;
            }
            }
        }



    return "у вас нет фото, чтобы его удалить";

}

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

