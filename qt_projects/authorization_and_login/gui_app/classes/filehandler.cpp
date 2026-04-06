#include "filehandler.h"
#include <QDir>
#include "logger.hpp"
#include <QJsonDocument>
#include <QJsonObject>
#include <QCoreApplication>
#include <QVector>
#include <QFileDialog>
#include <QVariant>
#include <QDir>

FileHandler::FileHandler() {}

QString FileHandler::path_to_data(QString path){


    QString current_filepath_str = QDir::currentPath();
    int pos = current_filepath_str.indexOf("authorization_and_login");
    QString main_folder_path = current_filepath_str.left(pos+QString("authorization_and_login").length());
    QString filepath = QDir(main_folder_path).filePath(path);
    return filepath;

}

void FileHandler::create_folder(QString folder_name){
    QDir dir(folder_name);
    if (!dir.exists()) {
        dir.mkpath(".");
        LOG_INFO("Папка photos создана впервые");

    } else {
        LOG_INFO("Папка photos уже существует, используем существующие фото");
    }
}
