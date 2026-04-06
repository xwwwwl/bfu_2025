#include "registration_window.h"
#include "ui_registration_window.h"
#include "logger.hpp"
#include "mainwindow.h"
#include <QRandomGenerator>
#include <QDebug>
#include "classes/func.h"


registration_window::registration_window(QWidget *parent, PhotoOperation* upload_photo, PhotoOperation* delete_photo, PhotoOperation* set_avatar_photo,UserFileHandler user_file_handler)
    : QDialog(parent)
    , ui(new Ui::registration_window)
    , upload_photo_(upload_photo)
    , delete_photo_(delete_photo)
    , set_avatar_photo_(set_avatar_photo)
    , user_file_handler_(user_file_handler)
{
    ui->setupUi(this);
    LOG_INFO("вы открыли окно регистрации");
    ui->Error_screen->setText("");
}

registration_window::~registration_window()
{
    delete ui;
}

void registration_window::on_back_to_mainwindow_clicked()
{

    MainWindow *mainwindow = new MainWindow(nullptr, 0, upload_photo_,delete_photo_,set_avatar_photo_, user_file_handler_);
    mainwindow->show();
    mainwindow->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}

void registration_window::on_registration_button_clicked()
{

    if( password_correct==false){
        ui->Error_screen->setText("недопустимые символы");
        return;
    }
    QString login = ui->login_registration->text();
    QString password = ui->password_registration->text();
    if (login.startsWith(" ")){
        LOG_INFO("Логин не может начинаться с пробела");
        ui->Error_screen->setText("пароль не может начинаться с пробела");
        return;
    }
    if (login.isEmpty() || password.isEmpty()) {
        LOG_INFO("Логин и пароль не могут быть пустыми!");
        ui->Error_screen->setText("логин или пароль не могут быть пустыми");
        return;
    }

    QVector<QVariant> user_information = user_file_handler_.find_user(login);
    // QJsonObject json_user = user_information[0].toJsonObject();


    if (!user_information.empty()){
        ui->Error_screen->setText("логин уже существует");
        return;
    }



    if (user_file_handler_.add_user(login,password)){
        ui->login_registration->clear();
        ui->password_registration->clear();
    }
    else {
        return;
    }
    MainWindow *mainwindow = new MainWindow(nullptr, 1, upload_photo_,delete_photo_,set_avatar_photo_,user_file_handler_);
    mainwindow->show();
    mainwindow->setAttribute(Qt::WA_DeleteOnClose);
    this->close();

}

void registration_window::on_password_registration_textChanged(const QString &arg1)
{

    if (error_flag_log ==false and error_flag_pas == false){
        ui->Error_screen->setText("");
    }
    QString alphabet = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890:;<=>?@^%'";
    QString password =ui->password_registration->text();
    password_correct=password_check(password,alphabet);
    if ( password_correct==false){
        ui->password_registration->setStyleSheet(
            "QLineEdit { border: 1px solid #B00000; "
            "   border-radius: 3px;}"
            );
        ui->Error_screen->setText("недопустимые символы");
        error_flag_pas=true;
    }
    else{
            ui->password_registration->setStyleSheet(
                "QLineEdit { border: 1px solid palette(mid); "
                "border-radius: 3px;}"
                );
            error_flag_pas=false;
        }

}


void registration_window::on_login_registration_textChanged(const QString &arg1)
{
    if (error_flag_log ==false and error_flag_pas == false){
        ui->Error_screen->setText("");
    }

    QString login =ui->login_registration->text();
    if (login.startsWith(" ")){
        ui->Error_screen->setText("логин не может начинаться с пробела");
        ui->login_registration->setStyleSheet(
            "QLineEdit { border: 1px solid #B00000; "
            "   border-radius: 3px;}"
            );
        error_flag_log=true;
    }
    else{
        ui->login_registration->setStyleSheet(
            "QLineEdit { border: 1px solid palette(mid); "
            "border-radius: 3px;}"
            );
        error_flag_log=false;

    }
}

