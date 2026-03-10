#include "registration_window.h"
#include "ui_registration_window.h"
#include "logger.hpp"
#include "mainwindow.h"
#include "user_class.h"
#include "func.h"
#include <QRandomGenerator>
#include <QDebug>

registration_window::registration_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registration_window)
{
    ui->setupUi(this);
    LOG_INFO("вы открыли окно регистрации");
    ui->Error_password->setVisible(false);
    ui->Error_login->setVisible(false);
    ui->you_not_regist->setVisible(false);


}

registration_window::~registration_window()
{
    delete ui;
}

void registration_window::on_back_to_mainwindow_clicked()
{

    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
    mainwindow->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}

void registration_window::on_registration_button_clicked()
{

    if( password_correct==false){
        ui->you_not_regist->setVisible(true);
        return;
    }
    QString login = ui->login_registration->text();
    QString password = ui->password_registration->text();
    if (login.startsWith(" ")){
        LOG_INFO("Логин не может начинаться с пробела");
        return;
    }
    if (login.isEmpty() || password.isEmpty()) {
        LOG_INFO("Логин и пароль не могут быть пустыми!");
        return;
    }

    QString file_path = find_path(QCoreApplication::applicationFilePath(),"password.jsonl");

    User current_user(login,password,file_path);


    if (current_user.login_user_check()){
        ui->Error_login->setText("такой логин уже существует, введите другой");
        ui->Error_login->setVisible(true);
        return;
    }



    if (current_user.add_user()){
        ui->login_registration->clear();
        ui->password_registration->clear();
    }
    else {
        return;
    }
    MainWindow *mainwindow = new MainWindow(nullptr, 1);
    mainwindow->show();
    mainwindow->setAttribute(Qt::WA_DeleteOnClose);
    this->close();

}

void registration_window::on_password_registration_textChanged(const QString &arg1)
{

    ui->you_not_regist->setVisible(false);
    QString alphabet = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890:;<=>?@^%'";
    QString password =ui->password_registration->text();

    password_correct=password_check(password,alphabet);
    if ( password_correct==false){
        ui->password_registration->setStyleSheet(
            "QLineEdit { border: 1px solid #B00000; "
            "   border-radius: 3px;}"
            );
        ui->Error_password->setVisible(true);
    }
    else{
            ui->password_registration->setStyleSheet(
                "QLineEdit { border: 1px solid palette(mid); "
                "border-radius: 3px;}"
                );
            ui->Error_password->setVisible(false);
        }

}


void registration_window::on_login_registration_textChanged(const QString &arg1)
{
    ui->Error_login->setVisible(false);
    ui->you_not_regist->setVisible(false);
    QString login =ui->login_registration->text();
    if (login.startsWith(" ")){
        ui->Error_login->setText("Недопустимые символы");
        ui->Error_login->setVisible(true);
        ui->login_registration->setStyleSheet(
            "QLineEdit { border: 1px solid #B00000; "
            "   border-radius: 3px;}"
            );
    }
    else{
        ui->login_registration->setStyleSheet(
            "QLineEdit { border: 1px solid palette(mid); "
            "border-radius: 3px;}"
            );
        ui->Error_password->setVisible(false);
    }
}

