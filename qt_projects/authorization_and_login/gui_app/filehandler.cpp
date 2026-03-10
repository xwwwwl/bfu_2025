#include "filehandler.h"
#include <QDir>
#include "logger.hpp"
#include <QJsonDocument>
#include <QJsonObject>
#include <QCoreApplication>
#include <QVector>
#include <QFileDialog>
#include <QVariant>


FileHandler::FileHandler() {}

QVector<QVariant> FileHandler::find_user(QString login, QString filepath){
    QString path_to_user_avatar;
    QFile file(filepath);


    if (!file.open(QIODevice::ReadOnly)) {
        LOG_INFO("Не удалось открыть файл");
    }

    QStringList allLines;
    QTextStream readStream(&file);

    while (!readStream.atEnd()) {
        allLines.append(readStream.readLine());
    }
    file.close();
    for (int i =0;i<allLines.length();i++){
        QJsonDocument doc=QJsonDocument::fromJson(allLines[i].toUtf8());
        QJsonObject Jobj = doc.object();
        if (Jobj["login"].toString()==login)
        {
            QVector<QVariant> list = {Jobj, i, allLines};
            return list;
        }

    }
    QVector<QVariant> list;
    return list;

}

QString FileHandler::write_user_info(QStringList All_Lines,  QString filepath){
    QFile file(filepath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        LOG_INFO("Не удалось открыть файл для записи");
        return "Не удалось открыть файл для записи";
    }
    QTextStream writeStream(&file);
    for (const QString& line :All_Lines) {
        writeStream << line << "\n";
    }
    file.close();
    LOG_INFO("Фото успешно загружено");
    return "файл успешно записан";
}

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





