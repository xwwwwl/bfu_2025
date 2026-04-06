#ifndef AUTHORIZATION_WINDOW_H
#define AUTHORIZATION_WINDOW_H


#include <QWidget>
#include "classes/photooperation.h"
#include "classes/user_file_handler.h"

namespace Ui {
class authorization_window;
}

class authorization_window : public QWidget
{
    Q_OBJECT

public:
    explicit authorization_window(QWidget *parent = nullptr, PhotoOperation* upload_photo = nullptr, PhotoOperation* delete_photo = nullptr, PhotoOperation* set_avatar_photo = nullptr, UserFileHandler user_file_handler= UserFileHandler(""));
    ~authorization_window();

private slots:
    void on_back_to_mainwindow_clicked();


    void on_authorization_button_clicked();

    void on_password_authorization_textChanged(const QString &arg1);

    void on_login_authorization_textChanged(const QString &arg1);

private:
    bool error_flag_log=false;
    bool error_flag_pas=false;
    UserFileHandler user_file_handler_;
    Ui::authorization_window *ui;
    PhotoOperation* upload_photo_;
    PhotoOperation* delete_photo_;
    PhotoOperation* set_avatar_photo_;

};

#endif // AUTHORIZATION_WINDOW_H
