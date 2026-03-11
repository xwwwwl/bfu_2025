#include "choose_window.h"
#include "ui_choose_window.h"
#include "classes/delete_photo.h"
#include "classes/set_avatar_photo.h"
#include "classes/func.h"
#include "classes/user_file_handler.h"
#include <QVector>
#include "logger.hpp"
#include <QPushButton>
#include <QWidget>
#include <QTimer>
#include "final_window.h"

choose_window::choose_window(QWidget *parent, User user)
    : QWidget(parent)
    , ui(new Ui::choose_window)
    , user_(user)
    , delete_photo(new DeletePhoto)
    , set_avatar_photo(new SetAvatarPhoto)
{
    ui->setupUi(this);
    ui->error_label->setVisible(false);

    photos = {ui->photo_1, ui->photo_2, ui->photo_3, ui->photo_4};
    UserFileHandler user_file(user_);
    defoalt_avatar_file_path = find_path(QCoreApplication::applicationFilePath(),"user_img.png");

    user_photo_path = user_file.get_vector_to_user_photo();

    for (int i = 0; i < user_photo_path.size(); i++) {
        if (user_photo_path[i] == "") {
            LOG_ERROR(QString("картинка %1 не загружена").arg(i + 1));
            return;
        }
        else if (user_photo_path[i] == "plug") {
            user_photo_path[i] = defoalt_avatar_file_path;

        }
    for (int i = 0; i < user_photo_path.size(); i++) {

        photos[i]->setPixmap(QPixmap(user_photo_path[i]));
    }
    }
        for (int i=0;i<photos.size();i++){
        QPushButton *btn = new QPushButton(photos[i]);
        btn->resize(photos[i]->width(), photos[i]->height());
        btn->setStyleSheet(
            "QPushButton {"
            "    border: 1px solid gray;"
            "    border-radius: 0px;"
            "    background-color: transparent;"
            "}"
            );
        connect(btn, &QPushButton::pressed, this, [this,i]() {
            onPhotoPressed(i);
        });
        connect(btn, &QPushButton::released, this, [this,i]() {
            onPhotoReleased(i);
        });
        photo_buttons.append(btn);
        }


}
void choose_window::onPhotoPressed(int photoNumber)
{
    ui->error_label->setVisible(false);

    photo_buttons[photoNumber]->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    border-radius: 0px;"
        "    background-color: rgba(255, 255, 255, 100);"
        "}"
        );
}
void choose_window::onPhotoReleased(int photoNumber){
    photo_buttons[photoNumber]->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    border-radius: 0px;"
        "    background-color: transparent;"
        "}"
        );
    photo_delete_or_avatar_path= user_photo_path[photoNumber];
    if (photo_delete_or_avatar_path==defoalt_avatar_file_path){
        photo_delete_or_avatar_path="plug";
    }
    LOG_INFO(photo_delete_or_avatar_path);

}

choose_window::~choose_window()
{
    delete ui;
    delete delete_photo;
    delete set_avatar_photo;
}

void choose_window::on_set_avatar_btn_clicked()
{
    if (photo_delete_or_avatar_path!=""){
        QString error_label_str = set_avatar_photo->execute(&user_, photo_delete_or_avatar_path);
        if (error_label_str=="файл успешно записан"){
            ui->error_label->setText("изображение аватара успешно обновлено");
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
    }
    else{
        ui->error_label->setText("выберете картинку");
        ui->error_label->setStyleSheet(
            "QLabel {"
            "color: #B00000;"
            "}"
            );
        ui->error_label->setVisible(true);
        LOG_ERROR("выбери картинку");
    }

}


void choose_window::on_delete_photo_btn_clicked()
{

    if (photo_delete_or_avatar_path!=""){

        UserFileHandler user_file(user_);
        QString error_label_str = delete_photo->execute(&user_, photo_delete_or_avatar_path);
        if (error_label_str=="файл успешно записан"){
            ui->error_label->setText("фото успешно удалено");
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
        user_photo_path = user_file.get_vector_to_user_photo();

        for (int i = 0; i < user_photo_path.size(); i++) {
            if (user_photo_path[i] == "") {
                LOG_ERROR(QString("картинка %1 не загружена").arg(i + 1));
                return;
            }
            else if (user_photo_path[i] == "plug") {
                user_photo_path[i] = defoalt_avatar_file_path;

            }
        for (int i = 0; i < user_photo_path.size(); i++) {

                photos[i]->setPixmap(QPixmap(user_photo_path[i]));
        }
        }
    }
    else{
        ui->error_label->setText("выберете картинку");
        ui->error_label->setStyleSheet(
            "QLabel {"
            "color: #B00000;"
            "}"
            );
        ui->error_label->setVisible(true);
        LOG_ERROR("выбери картинку");
    }
}


void choose_window::on_back_to_mainwindow_clicked()
{
    final_window* final_window_1 = new final_window(nullptr, user_);
    final_window_1->show();
    this->close();
}


