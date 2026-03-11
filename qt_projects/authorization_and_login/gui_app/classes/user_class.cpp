#include <QDir>
#include "logger.hpp"
#include <QJsonDocument>
#include <QJsonObject>
#include <QCoreApplication>
#include "user_class.h"
#include <QRandomGenerator>
#include "func.h"

User::User(QString login,QString password, QString filepath)
    :login_(login), password_(password), filepath_(filepath) {}

bool User::add_user(){
    QJsonObject user;
    int id = getLastId(filepath_);
    int key = static_cast<int>(QRandomGenerator::global()->generate());
    QString password=encoder(password_, key);
    id_=id;


    user["id"] = id;
    user["login"] = login_;
    user["password"] = password;
    user["key"] = key;
    user["avatar"]="photo_1";
    user["photo_1"]="plug";
    user["photo_2"]="plug";
    user["photo_3"]="plug";
    user["photo_4"]="plug";

    QFile file(filepath_);
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
    } else {
        LOG_INFO("Ошибка при записи в файл!");
        return 0;
    }
}

bool User::user_check(){

    QFile file(filepath_);

    if (!file.open(QIODevice::QIODevice::ReadOnly)) {
        LOG_INFO("Не удалось открыть файл");
        return 0;
    }

    QTextStream data(&file);

    while(!data.atEnd()){
        QString line =data.readLine();
        QJsonDocument doc = QJsonDocument::fromJson(line.toUtf8());
        QJsonObject JsonObject = doc.object();

        int key=JsonObject["key"].toInt();
        QString login_in_data = JsonObject["login"].toString();
        QString password_in_data = JsonObject["password"].toString();
        QString password=encoder(password_, key);
        if (login_in_data == login_ && password_in_data==password){
            id_=JsonObject["id"].toInt();
            return 1;
        }
    }
    LOG_INFO("нет такого пользователя");
    return 0;
}

bool User::login_user_check(){
    QFile file(filepath_);

    if (!file.open(QIODevice::QIODevice::ReadOnly)) {
        LOG_INFO("Не удалось открыть файл");
        return 0;
    }

    QTextStream data(&file);

    while(!data.atEnd()){
        QString line =data.readLine();
        QJsonDocument doc = QJsonDocument::fromJson(line.toUtf8());
        QJsonObject JsonObject = doc.object();
        QString login_in_data = JsonObject["login"].toString();
        if (login_in_data == login_){
            return 1;
        }
    }
    LOG_INFO("нет такого пользователя");
    return 0;
}

int User::get_id(){
    return id_;
}



int getLastId(const QString& filePath) {
    QFile file(filePath);

    if (!file.open(QIODevice::QIODevice::ReadOnly)) {
        LOG_INFO("Не удалось открыть файл");
        return 0;
    }

    QString lastLine;

    while (!file.atEnd()) lastLine = file.readLine();
    file.close();

    return QJsonDocument::fromJson(lastLine.toUtf8()).object()["id"].toInt();
}

bool password_check(QString password, QString alphabet){
    for (QChar c : password){
        if(!alphabet.contains(c)){
            return false;
        }
    }
    return true;
}

QString User::get_login(){
    return login_;
}

QString User::get_filepath(){
    return filepath_;
}

QString User::get_password(){
    return password_;
}




