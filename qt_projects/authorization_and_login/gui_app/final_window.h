#ifndef FINAL_WINDOW_H
#define FINAL_WINDOW_H

#include <QWidget>
#include "classes/user_class.h"
#include "classes/photo_file_handler.h"
#include "classes/user_file_handler.h"

#include "classes/photooperation.h"

namespace Ui {
class final_window;
}

class final_window : public QWidget
{
    Q_OBJECT

public:
    explicit final_window(QWidget *parent = nullptr, QString login = "", PhotoOperation* upload_photo = nullptr, PhotoOperation* delete_photo = nullptr, PhotoOperation* set_avatar_photo = nullptr, UserFileHandler user_file_handler= UserFileHandler(""));
    ~final_window();

private slots:
    void on_upload_btn_clicked();

    void on_choose_btn_clicked();

    void on_back_to_mainwindow_clicked();

private:
    UserFileHandler user_file_handler_;
    QString login_;
    PhotoOperation* upload_photo_;
    PhotoOperation* delete_photo_;
    PhotoOperation* set_avatar_photo_;
    Ui::final_window *ui;
};
#endif // FINAL_WINDOW_H
