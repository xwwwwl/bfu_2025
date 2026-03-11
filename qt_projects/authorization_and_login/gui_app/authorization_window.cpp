#include "authorization_window.h"
#include "ui_authorization_window.h"
#include "mainwindow.h"
#include "logger.hpp"
#include "classes/user_class.h"
#include <QDebug>
#include "final_window.h"
#include "func.h"


authorization_window::authorization_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::authorization_window)
{
    ui->setupUi(this);
    ui->Error_password->setVisible(false);
    ui->Error_registration->setVisible(false);
    ui->you_not_regist->setVisible(false);
    LOG_INFO("вы создали окно авторизации");
}

authorization_window::~authorization_window()
{
    delete ui;
}

void authorization_window::on_back_to_mainwindow_clicked()
{

    MainWindow *mainwindow_1 = new MainWindow();
    mainwindow_1->show();
    mainwindow_1->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}



void authorization_window::on_authorization_button_clicked()
{
    QString login = ui->login_authorization->text();
    QString password = ui->password_authorization->text();
    QString file_path =find_path(QCoreApplication::applicationDirPath(),"password.jsonl");
    User current_user(login,password,file_path);

    if (login.startsWith(" ")){
        LOG_INFO("Логин не может начинаться с пробела");
        return;
    }
    QFile file(file_path);

    if (!file.open(QIODevice::QIODevice::ReadOnly)) {
        LOG_INFO("Не удалось открыть файл");
        return ;
    }

    if (current_user.user_check())
    {
        final_window *final_window_1 = new final_window(nullptr,current_user);
        final_window_1->show();
        final_window_1->setAttribute(Qt::WA_DeleteOnClose);
        this->close();
        return;
        }

    ui->you_not_regist->setVisible(true);


}


void authorization_window::on_password_authorization_textChanged(const QString &arg1)
{
    ui->you_not_regist->setVisible(false);
    ui->Error_password->setVisible(false);

    QString alphabet = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890:;<=>?@^%'";
    QString password =ui->password_authorization->text();


    bool password_correct=password_check(password,alphabet);
    if ( password_correct==false){
        ui->password_authorization->setStyleSheet(
            "QLineEdit { border: 1px solid #B00000; "
            "   border-radius: 3px;}"
            );
        ui->Error_password->setVisible(true);
    }
    else{
        ui->password_authorization->setStyleSheet(
            "QLineEdit { border: 1px solid palette(mid); "
            "border-radius: 3px;}"
            );
        ui->Error_password->setVisible(false);
    }
}


void authorization_window::on_login_authorization_textChanged(const QString &arg1)
{
    ui->Error_registration->setVisible(false);
    ui->you_not_regist->setVisible(false);
    QString login =ui->login_authorization->text();
    if (login.startsWith(" ")){
        ui->login_authorization->setStyleSheet(
            "QLineEdit { border: 1px solid #B00000; "
            "   border-radius: 3px;}"
            );
        ui->Error_registration->setVisible(true);
    }
    else{
        ui->login_authorization->setStyleSheet(
            "QLineEdit { border: 1px solid palette(mid); "
            "border-radius: 3px;}"
            );
        ui->Error_password->setVisible(false);
    }
}

