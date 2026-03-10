#ifndef FINAL_WINDOW_H
#define FINAL_WINDOW_H

#include <QWidget>
#include "user_class.h"
#include "photooperation.h"

namespace Ui {
class final_window;
}

class final_window : public QWidget
{
    Q_OBJECT

public:
    explicit final_window(QWidget *parent = nullptr, User user = defaultUser());
    ~final_window();

private slots:
    void on_upload_btn_clicked();

    void on_choose_btn_clicked();

    void on_back_to_mainwindow_clicked();

private:
    static User defaultUser() {
        return User("", "", "");
    }
    PhotoOperation*  upload_photo;
    Ui::final_window *ui;
    User user_;
};
#endif // FINAL_WINDOW_H
