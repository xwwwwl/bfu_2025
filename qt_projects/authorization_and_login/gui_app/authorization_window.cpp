#include "authorization_window.h"
#include "ui_authorization_window.h"
#include "mainwindow.h"
#include "logger.hpp"
#include "classes/user_class.h"
#include <QDebug>
#include "final_window.h"
#include "classes/func.h"



authorization_window::authorization_window(QWidget *parent, PhotoOperation* upload_photo, PhotoOperation* delete_photo, PhotoOperation* set_avatar_photo,UserFileHandler user_file_handler)
    : QWidget(parent)
    , ui(new Ui::authorization_window)
    , upload_photo_(upload_photo)
    , delete_photo_(delete_photo)
    , set_avatar_photo_(set_avatar_photo)
    , user_file_handler_(user_file_handler)
{
    ui->setupUi(this);
    ui->Error_screen->setText("");

    LOG_INFO("вы создали окно авторизации");
}

authorization_window::~authorization_window()
{
    delete ui;
}

void authorization_window::on_back_to_mainwindow_clicked()
{

    MainWindow *mainwindow_1 = new MainWindow(nullptr, 0,upload_photo_,delete_photo_,set_avatar_photo_,user_file_handler_);
    mainwindow_1->show();
    mainwindow_1->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}



void authorization_window::on_authorization_button_clicked()
{
    QString login = ui->login_authorization->text();
    QString password = ui->password_authorization->text();

    if (login.startsWith(" ")){
        LOG_INFO("Логин не может начинаться с пробела");
        ui->Error_screen->setText("логин не может начинаться с пробела");
        return;
    }
    QVector<QVariant> user_information = user_file_handler_.find_user(login);

    if (!user_information.empty())
    {
        QJsonObject user_json = user_information[0].toJsonObject();
        if (user_file_handler_.user_check(login,password, user_json)){
            final_window *final_window_1 = new final_window(nullptr,login,upload_photo_,delete_photo_,set_avatar_photo_, user_file_handler_);
            final_window_1->show();
            final_window_1->setAttribute(Qt::WA_DeleteOnClose);
            this->close();
            return;
        }

        }

    ui->Error_screen->setText("логин или пароль написаны не верно");


}


void authorization_window::on_password_authorization_textChanged(const QString &arg1)
{
    if (error_flag_log ==false and error_flag_pas == false){
        ui->Error_screen->setText("");
    }

    QString alphabet = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890:;<=>?@^%'";
    QString password =ui->password_authorization->text();


    bool password_correct=password_check(password,alphabet);
    if ( password_correct==false){
        ui->password_authorization->setStyleSheet(
            "QLineEdit { border: 1px solid #B00000; "
            "   border-radius: 3px;}"
            );
        error_flag_pas=true;
        ui->Error_screen->setText("недопустимые символы");
    }
    else{
        ui->password_authorization->setStyleSheet(
            "QLineEdit { border: 1px solid palette(mid); "
            "border-radius: 3px;}"
            );
        error_flag_pas=false;

    }
}


void authorization_window::on_login_authorization_textChanged(const QString &arg1)
{
    if (error_flag_log ==false and error_flag_pas == false){
        ui->Error_screen->setText("");
    }
    QString login =ui->login_authorization->text();
    if (login.startsWith(" ")){
        ui->login_authorization->setStyleSheet(
            "QLineEdit { border: 1px solid #B00000; "
            "   border-radius: 3px;}"
            );
        ui->Error_screen->setText("логин не может начинаться с пробела");
        error_flag_log=true;
    }
    else{
        ui->login_authorization->setStyleSheet(
            "QLineEdit { border: 1px solid palette(mid); "
            "border-radius: 3px;}"
            );
        error_flag_log=false;

    }
}

