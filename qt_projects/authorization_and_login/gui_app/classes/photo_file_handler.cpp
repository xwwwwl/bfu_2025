#include "photo_file_handler.h"
#include "logger.hpp"
#include <QFile>

bool photo_file_handler::CopyPhoto(QString PhotoPath, QString NewPhotoPath){
    if (!QFile::copy(PhotoPath, NewPhotoPath)) {
        LOG_ERROR("Не удалось скопировать фото: " + PhotoPath);
        return false;
    }
    return true;
}

bool  photo_file_handler::DeletePhoto(QString PhotoPath){
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
