#include "choose_window.h"
#include "ui_choose_window.h"
#include "classes/func.h"
#include "classes/user_file_handler.h"
#include <QVector>
#include "logger.hpp"
#include <QPushButton>
#include <QWidget>
#include <QTimer>
#include "final_window.h"
#include <QJsonObject>


choose_window::choose_window(QWidget *parent, QString login, PhotoOperation* upload_photo, PhotoOperation* delete_photo, PhotoOperation* set_avatar_photo,UserFileHandler user_file_handler)
    : QWidget(parent)
    , ui(new Ui::choose_window)
    , login_(login)
    , upload_photo_(upload_photo)
    , delete_photo_(delete_photo)
    , set_avatar_photo_(set_avatar_photo)
    , user_file_handler_(user_file_handler)
{
    ui->setupUi(this);
    ui->error_label->setVisible(false);

    photos = {ui->photo_1_btn, ui->photo_2_btn, ui->photo_3_btn, ui->photo_4_btn};
    defoalt_avatar_file_path = find_path(QCoreApplication::applicationFilePath(),"user_img.png");
    QVector<QVariant> user_information = user_file_handler_.find_user(login_);
    QJsonObject json_user = user_information[0].toJsonObject();
    user_photo_path = user_file_handler_.get_vector_to_user_photo(json_user);
    for (int i=0; i<user_photo_path.length(); i++){
        group->addButton(photos[i]);
        QString photopath = user_photo_path[i];
        if (photopath == "plug") {
            photos[i]->setIcon(QIcon(defoalt_avatar_file_path));
        }
        else if(photopath == "") {
            LOG_ERROR("не удалось найти фото");
            return;
        }
        else {
            photos[i]->setIcon(QIcon(photopath));
        }

        photos[i]->setStyleSheet("QPushButton::checked { border: 3px solid green; }" );
        photos[i]->setIconSize(QSize(120, 120));

    }
    for (auto* btn : photos) {
        btn->installEventFilter(this);  // <- ДОБАВЬТЕ ЭТО
    }

    group->setExclusive(true);






}


choose_window::~choose_window()
{
    delete ui;

}
bool choose_window::eventFilter(QObject* watched, QEvent* event)
{
    for (int i=0; i<user_photo_path.length(); i++){
        QString photopath = user_photo_path[i];
        if (photopath != "plug") {
             photos[i]->setIcon(QIcon(photopath));
        }

    }
        for (auto* btn : photos) {
            int w = btn->width();
            int h = btn->height();
            int minimal_w_h = std::min(w,h);
            btn->resize(minimal_w_h, minimal_w_h);
            btn->setIconSize(QSize(static_cast<int>(minimal_w_h * 0.95),
                                   static_cast<int>(minimal_w_h * 0.95)));
            btn->update();

        }

    return QWidget::eventFilter(watched, event);
}
void choose_window::on_set_avatar_btn_clicked()
{
    for (int i=0; i<user_photo_path.length(); i++){
        if (photos[i]->isChecked()){
            QString user_photopath =user_photo_path[i];
            QString error_label_str = set_avatar_photo_->execute(login_, user_photopath);
            if (error_label_str=="файл успешно записан"){
                ui->error_label->setText("изображение аватара успешно обновлено");
                ui->error_label->setStyleSheet(
                    "QLabel {"
                    "color: #32CD32;"
                    "}"
                    );
                ui->error_label->setVisible(true);
                return;
            }
            else{
                ui->error_label->setText(error_label_str);
                ui->error_label->setStyleSheet(
                    "QLabel {"
                    "color: #B00000;"
                    "}"
                    );
                ui->error_label->setVisible(true);
                return;
            }
        }
    }
    ui->error_label->setText("выберите картинку");
    ui->error_label->setStyleSheet(
        "QLabel {"
        "color: #B00000;"
        "}"
        );
    ui->error_label->setVisible(true);
    LOG_ERROR("выбери картинку");
    }




void choose_window::on_delete_photo_btn_clicked()
{
    for (int i=0; i<user_photo_path.length(); i++){
        if (photos[i]->isChecked()){
            QString user_photopath =user_photo_path[i];
            QString error_label_str = delete_photo_->execute(login_, user_photopath);
            if (error_label_str=="файл успешно записан"){
                ui->error_label->setText("фото успешно удалено");
                ui->error_label->setStyleSheet(
                    "QLabel {"
                    "color: #32CD32;"
                    "}"
                    );
                ui->error_label->setVisible(true);
                QVector<QVariant> user_information = user_file_handler_.find_user(login_);
                QJsonObject json_user = user_information[0].toJsonObject();
                user_photo_path = user_file_handler_.get_vector_to_user_photo(json_user);
                for (int i=0; i<user_photo_path.length(); i++){
                    QString photopath = user_photo_path[i];
                    if (photopath == "plug") {
                        photos[i]->setIcon(QIcon(defoalt_avatar_file_path));
                    }
                    else if(photopath == "") {
                        LOG_ERROR("не удалось найти фото");
                        return;
                    }
                    else {
                        photos[i]->setIcon(QIcon(photopath));
                    }



                    }
                for (auto* btn : photos) {
                        int w = btn->width();
                        int h = btn->height();
                        int minimal_w_h = std::min(w,h);
                        btn->resize(minimal_w_h, minimal_w_h);
                        btn->setIconSize(QSize(static_cast<int>(minimal_w_h * 0.95),
                                               static_cast<int>(minimal_w_h * 0.95)));
                        btn->update();

                }
                return ;
            }
            else{
                ui->error_label->setText(error_label_str);
                ui->error_label->setStyleSheet(
                    "QLabel {"
                    "color: #B00000;"
                    "}"
                    );
                ui->error_label->setVisible(true);
                return ;
            }
        }
    }



    ui->error_label->setText("выберите картинку");
    ui->error_label->setStyleSheet(
        "QLabel {"
        "color: #B00000;"
        "}"
        );
    ui->error_label->setVisible(true);
    LOG_ERROR("выбери картинку");

}


void choose_window::on_back_to_mainwindow_clicked()
{

    final_window* final_window_1 = new final_window(nullptr, login_, upload_photo_,delete_photo_,set_avatar_photo_, user_file_handler_);
    final_window_1->show();
    this->close();
}


