#ifndef CHOOSE_WINDOW_H
#define CHOOSE_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QPushButton>
#include <QJsonObject>
#include "classes/photooperation.h"
#include "classes/user_file_handler.h"
#include <QButtonGroup>

namespace Ui {
class choose_window;
}

class choose_window : public QWidget
{
    Q_OBJECT

public:
    explicit choose_window(QWidget *parent = nullptr, QString login = "" , PhotoOperation* upload_photo = nullptr, PhotoOperation* delete_photo = nullptr, PhotoOperation* set_avatar_photo = nullptr, UserFileHandler user_file_handler= UserFileHandler(""));
    ~choose_window();
private slots:


    void on_set_avatar_btn_clicked();

    void on_delete_photo_btn_clicked();

    void on_back_to_mainwindow_clicked();
protected:
    bool eventFilter(QObject* watched, QEvent* event) override;  // <- ДОБАВЬТЕ ЭТО
private:
    QJsonObject json_user;
    UserFileHandler user_file_handler_;
    PhotoOperation* upload_photo_;
    PhotoOperation* delete_photo_;
    PhotoOperation* set_avatar_photo_;
    Ui::choose_window *ui;
    QString login_;
    QButtonGroup *group = new QButtonGroup(this);
    QVector<QPushButton*> photos;
    QVector<QString> user_photo_path;
    QString defoalt_avatar_file_path;


};

#endif // CHOOSE_WINDOW_H
