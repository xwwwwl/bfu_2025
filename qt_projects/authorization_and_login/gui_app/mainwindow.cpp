#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "logger.hpp"
#include "authorization_window.h"
#include "registration_window.h"


MainWindow::MainWindow(QWidget *parent, bool flag_regist)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , flag_regist_(flag_regist)
{
    ui->setupUi(this);
    if (flag_regist_==1){
        ui->yout_regist->setVisible(true);
    }
    else{
        ui->yout_regist->setVisible(false);
    }
   LOG_INFO("вы открыли mainwindow");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_go_to_authorization_windows_clicked()
{
    authorization_window *authorization_window_1 = new authorization_window();

    authorization_window_1->show();
    authorization_window_1->setAttribute(Qt::WA_DeleteOnClose);
    this->close();

}


void MainWindow::on_go_to_registration_windows_clicked()
{
    registration_window *registration_window_1 = new registration_window();
    registration_window_1->show();
    registration_window_1->setAttribute(Qt::WA_DeleteOnClose);
    this->close();

}

