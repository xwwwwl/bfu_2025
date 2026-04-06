#ifndef REGISTRATION_WINDOW_H
#define REGISTRATION_WINDOW_H

#include <QDialog>
#include "classes/photooperation.h"
#include "classes/user_file_handler.h"

QString encoder(QString password, int key);
namespace Ui {
class registration_window;
}

class registration_window : public QDialog
{
    Q_OBJECT

public:
    explicit registration_window(QWidget *parent = nullptr, PhotoOperation* upload_photo = nullptr, PhotoOperation* delete_photo = nullptr, PhotoOperation* set_avatar_photo = nullptr, UserFileHandler user_file_handler= UserFileHandler(""));
    ~registration_window();

private slots:
    void on_back_to_mainwindow_clicked();

    void on_registration_button_clicked();

    void on_password_registration_textChanged(const QString &arg1);

    void on_login_registration_textChanged(const QString &arg1);

private:
    bool error_flag_log=false;
    bool error_flag_pas=false;
    UserFileHandler user_file_handler_;
    Ui::registration_window *ui;
    bool password_correct = true;
    PhotoOperation* upload_photo_;
    PhotoOperation* delete_photo_;
    PhotoOperation* set_avatar_photo_;
};

#endif // REGISTRATION_WINDOW_H
