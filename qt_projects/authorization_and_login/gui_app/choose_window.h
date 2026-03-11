#ifndef CHOOSE_WINDOW_H
#define CHOOSE_WINDOW_H

#include <QWidget>
#include "classes/user_class.h"
#include <QPushButton>
#include <QLabel>
#include "classes/photooperation.h"
namespace Ui {
class choose_window;
}

class choose_window : public QWidget
{
    Q_OBJECT

public:
    explicit choose_window(QWidget *parent = nullptr, User user = defualtUser());
    ~choose_window();
private slots:
    void onPhotoPressed(int index);
    void onPhotoReleased(int index);

    void on_set_avatar_btn_clicked();

    void on_delete_photo_btn_clicked();

    void on_back_to_mainwindow_clicked();

private:
    static User defualtUser(){
        return User("", "", "");
    }
    PhotoOperation* delete_photo;
    PhotoOperation* set_avatar_photo;
    Ui::choose_window *ui;
    User user_;
    QVector<QPushButton*> photo_buttons;
    QString photo_delete_or_avatar_path ="";
    QVector<QLabel*> photos;
    QVector<QString> user_photo_path;
    QString defoalt_avatar_file_path;


};

#endif // CHOOSE_WINDOW_H
