#include "final_window.h"
#include "ui_final_window.h"
#include "filehandler.h"
#include "func.h"

#include <QFileDialog>
#include "choose_window.h"
#include "mainwindow.h"
#include "photooperation.h"




final_window::final_window(QWidget *parent ,User user)
    : QWidget(parent)
    , ui(new Ui::final_window)
    , user_(user)
    , upload_photo(new UploadPhoto)
{
    ui->setupUi(this);
    ui->error_label->setVisible(false);
    QString login =user.get_login();
    ui->user_label->setText(login);
    UserFileHandler user_file(user_);
    QString avatar_path = user_file.get_path_to_user_avatar();
    if (avatar_path=="plug"){
        QString file_path = find_path(QCoreApplication::applicationFilePath(),"user_img.png");
        ui->avatar->setPixmap(QPixmap(file_path));
    }
    else{
        ui->avatar->setPixmap(QPixmap(avatar_path));
    }

    QString dir_path = find_path(user_.get_filepath(),"")+ "/photos/";
    QDir dir(dir_path);
    if (!dir.exists()) {
        dir.mkpath(".");  // Создается ТОЛЬКО если папки еще нет
        qDebug() << "Папка photos создана впервые";
    } else {
        qDebug() << "Папка photos уже существует, используем существующие фото";
    }


}

final_window::~final_window()
{
    delete ui;
    delete upload_photo;
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
        UserFileHandler user_file(user_);
        QString error_label_str =  upload_photo->execute(&user_,new_photo_filepath);
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
        QString avatar_path = user_file.get_path_to_user_avatar();
        if (avatar_path=="plug"){
            QString file_path = find_path(QCoreApplication::applicationFilePath(),"user_img.png");
            ui->avatar->setPixmap(QPixmap(file_path));
        }
        else{
            ui->avatar->setPixmap(QPixmap(avatar_path));
        }

    }

}


void final_window::on_choose_btn_clicked()
{
    choose_window* choose_window_1 = new choose_window(nullptr, user_);
    choose_window_1->show();
    this->close();
}


void final_window::on_back_to_mainwindow_clicked()
{
    MainWindow* main_window_1 = new MainWindow(nullptr,0);
    main_window_1->show();
    this->close();
}

