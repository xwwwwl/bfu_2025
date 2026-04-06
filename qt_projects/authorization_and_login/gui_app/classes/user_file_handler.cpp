#include "user_file_handler.h"
#include <QJsonObject>
#include "logger.hpp"
#include <QFile>
#include <QRandomGenerator64>
#include "func.h"

UserFileHandler::UserFileHandler(QString filepath)
    : filepath_(filepath) {
    QFile file(filepath);


    if (!file.exists()) {

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            file.close();
            LOG_INFO("файл " + filepath + " создан впервые");
        } else {
            LOG_ERROR("Не удалось создать файл: " + filepath);
        }
    } else {
        LOG_INFO("файл " + filepath + " уже существует, используем существующий");
    }
}

QString UserFileHandler::get_path_to_user_avatar(QJsonObject user_Json){
    QString path_to_user_avatar = user_Json[user_Json["avatar"].toString()].toString();
    return path_to_user_avatar;
}


QVector<QString> UserFileHandler::get_vector_to_user_photo(QJsonObject user_Json){
    QVector<QString> user_photo = {user_Json["photo_1"].toString(),user_Json["photo_2"].toString(),user_Json["photo_3"].toString(),user_Json["photo_4"].toString()};
    return user_photo;

}

QVector<QVariant> UserFileHandler::find_user(QString login){
    LOG_INFO(filepath_);
    QFile file(filepath_);


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

QString UserFileHandler::write_user_info(QStringList All_Lines){
    QFile file(filepath_);
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

QString UserFileHandler::get_filepath(){
    return filepath_;
}

bool UserFileHandler::add_user(QString login_, QString password_){
    QFile file(filepath_);
    if (!file.open(QIODevice::QIODevice::ReadOnly)) {
        LOG_INFO("Не удалось открыть файл");
        return 0;
    }

    int id = 0;
    QTextStream in(&file);

    while (!in.atEnd()) {
        in.readLine();
        id++;
    }
    file.close();
    QJsonObject user;

    int key = static_cast<int>(QRandomGenerator::global()->generate());
    QString password=encoder(password_, key);

    user["id"] = id;
    user["login"] = login_;
    user["password"] = password;
    user["key"] = key;
    user["avatar"]="photo_1";
    user["photo_1"]="plug";
    user["photo_2"]="plug";
    user["photo_3"]="plug";
    user["photo_4"]="plug";

    if (!file.open(QIODevice::QIODevice::Append)) {
        LOG_INFO("Не удалось открыть файл!");
        return 0;
    }

    QJsonDocument doc(user);
    QString line = doc.toJson(QJsonDocument::Compact) + "\n";
    qint64 bytesWritten = file.write(line.toUtf8());
    file.close();


    if (bytesWritten > 0) {
        LOG_INFO("Пользователь успешно добавлен! ID: " + QString::number(id));
        return 1;
    }
    return 0;
}

bool UserFileHandler::user_check(QString login, QString password, QJsonObject user_json){
    QString password_data = user_json["password"].toString();
    QString login_data = user_json["login"].toString();
    int key = user_json["key"].toInt();
    password = encoder(password,key);
    LOG_INFO(password_data);
    LOG_INFO(login_data);
    if (password==password_data && login== login_data){
        return 1;
    }
    return 0;
}
