#include "final_window.h"
#include "ui_final_window.h"
#include "classes/user_file_handler.h"
#include "func.h"
#include <QFileDialog>
#include "choose_window.h"
#include "mainwindow.h"
#include "classes/photooperation.h"
#include <QJsonObject>





final_window::final_window(QWidget *parent ,QString login, PhotoOperation* upload_photo, PhotoOperation* delete_photo, PhotoOperation* set_avatar_photo,UserFileHandler user_file_handler)
    : QWidget(parent)
    , ui(new Ui::final_window)
    , login_(login)
    , upload_photo_(upload_photo)
    , delete_photo_(delete_photo)
    , set_avatar_photo_(set_avatar_photo)
    , user_file_handler_(user_file_handler)
{
    ui->setupUi(this);
    ui->error_label->setVisible(false);
    ui->user_label->setText(login_);

    QVector<QVariant> user_information = user_file_handler_.find_user(login_);
    QJsonObject json_user = user_information[0].toJsonObject();
    QString avatar_path = user_file_handler_.get_path_to_user_avatar(json_user);
    QPixmap photo;

    if (avatar_path == "plug") {
        QString file_path = find_path(QCoreApplication::applicationFilePath(), "user_img.png");
        photo.load(file_path);
    } else {
        photo.load(avatar_path);
    }
    int targetWidth = 200;
    int targetHeight = 200;
    QPixmap scaled = photo.scaled(targetWidth, targetHeight,
                                     Qt::KeepAspectRatio,      // Сохранять пропорции
                                     Qt::SmoothTransformation); // Высокое качество

    ui->avatar->setPixmap(scaled);

}

final_window::~final_window()
{
    delete ui;
}

void final_window::on_upload_btn_clicked()
{
    QString new_photo_filepath = QFileDialog::getOpenFileName(
        this,
        "Выбрать изображение",
        "C:/",
        "Изображения (*.jpg *.jpeg *.png)"
        );
    if (new_photo_filepath!=""){

        QString error_label_str =  upload_photo_->execute(login_,new_photo_filepath);
        if (error_label_str =="файл успешно записан"){
            ui->error_label->setText("Фото успешно загружено");
            ui->error_label->setStyleSheet(
                "QLabel {"
                "color: #32CD32;"
            "}"
                );
            ui->error_label->setVisible(true);
        }
        else{
            ui->error_label->setText(error_label_str);
            ui->error_label->setStyleSheet(
                "QLabel {"
                "color: #B00000;"
                "}"
                );
            ui->error_label->setVisible(true);
        }
        QVector<QVariant> user_information = user_file_handler_.find_user(login_);
        QJsonObject json_user = user_information[0].toJsonObject();
        QString avatar_path = user_file_handler_.get_path_to_user_avatar(json_user);
        QPixmap photo;
        if (avatar_path == "plug") {
            QString file_path = find_path(QCoreApplication::applicationFilePath(), "user_img.png");
            photo.load(file_path);
        } else {
            photo.load(avatar_path);
        }
        int targetWidth = 200;
        int targetHeight = 200;
        QPixmap scaled = photo.scaled(targetWidth, targetHeight,
                                      Qt::KeepAspectRatio,      // Сохранять пропорции
                                      Qt::SmoothTransformation); // Высокое качество

        ui->avatar->setPixmap(scaled);

    }

}


void final_window::on_choose_btn_clicked()
{
    choose_window* choose_window_1 = new choose_window(nullptr, login_,upload_photo_,delete_photo_,set_avatar_photo_, user_file_handler_);
    choose_window_1->show();
    this->close();
}


void final_window::on_back_to_mainwindow_clicked()
{
    MainWindow* main_window_1 = new MainWindow(nullptr,0,upload_photo_,delete_photo_,set_avatar_photo_, user_file_handler_);
    main_window_1->show();
    this->close();
}

