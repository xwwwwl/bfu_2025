#include "mainwindow.h"
#include <QStyleFactory>
#include <QApplication>
#include "classes/upload_photo.h"
#include "classes/delete_photo.h"
#include "classes/set_avatar_photo.h"
#include "classes/photo_file_handler.h"
#include "classes/user_file_handler.h"
#include "classes/filehandler.h"
#include "logger.hpp"



int main(int argc, char *argv[])
{
    // проверять в upload photo и прочих сущестыует ли юзер (юзер файл хэндлер)
    // создаем фото юзер пока без лоигна а потмо он обновится

    FileHandler file_handler;
    QString path_to_data1= file_handler.path_to_data("password.jsonl");
    LOG_INFO(path_to_data1);
    PhotoFileHandler photo_file_handler;
    UserFileHandler user_file_handler(path_to_data1);

    PhotoOperation* upload_photo=new UploadPhoto(photo_file_handler,user_file_handler);
    PhotoOperation* delete_photo= new DeletePhoto(photo_file_handler,user_file_handler);
    PhotoOperation* set_avatar_photo = new SetAvatarPhoto(user_file_handler);
    QApplication a(argc, argv);

    a.setStyle("Fusion");

    MainWindow w(nullptr, 0, upload_photo,delete_photo,set_avatar_photo,user_file_handler);
    w.show();
    return a.exec();
}
