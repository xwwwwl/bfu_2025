#include "photo_file_handler.h"
#include "logger.hpp"
#include <QFile>
#include <QDir>
#include "logger.hpp"

PhotoFileHandler::PhotoFileHandler(){
    QString dir_path = path_to_data("/photos/");
    create_folder(dir_path);
}

bool PhotoFileHandler::CopyPhoto(QString PhotoPath, QString NewPhotoPath){
    LOG_INFO(PhotoPath);
    LOG_INFO(NewPhotoPath);
    if (!QFile::copy(PhotoPath, NewPhotoPath)) {
        LOG_ERROR("Не удалось скопировать фото: " + PhotoPath);
        return false;
    }
    return true;
}

bool PhotoFileHandler::DeletePhoto(QString PhotoPath){
    QFile delete_file(PhotoPath);
    if (delete_file.exists()) {
        if (delete_file.remove()) {
            LOG_INFO("Фото успешно удалено");
            return true;

        } else {
            LOG_INFO("Ошибка при удалении фото");
            return false;
        }
    } else {
        LOG_INFO("Файл не существует");
        return false;
    }
    return false;
}

bool PhotoFileHandler::DeleteAllEmptyFolder(QString PhotoPath)
{
    QString path = PhotoPath;
    int pos = path.lastIndexOf("/");

    while (pos != -1) {
        QString photoFolder = path.left(pos);
        QDir dir(photoFolder);
        if (dir.exists() && dir.isEmpty()) {
            if (!dir.removeRecursively()) {
                return false;
            }
        }

        path = photoFolder;
        pos = path.lastIndexOf("/");
    }

    return true;
}
