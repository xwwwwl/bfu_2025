#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "classes/photooperation.h"
#include "classes/user_file_handler.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>




QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, bool flag_regist=0, PhotoOperation* upload_photo = nullptr, PhotoOperation* delete_photo = nullptr, PhotoOperation* set_avatar_photo = nullptr, UserFileHandler user_file_handler= UserFileHandler(""));
    ~MainWindow();

private slots:
    void on_go_to_authorization_windows_clicked();

    void on_go_to_registration_windows_clicked();

private:

    UserFileHandler user_file_handler_;
    Ui::MainWindow *ui;
    PhotoOperation* upload_photo_;
    PhotoOperation* delete_photo_;
    PhotoOperation* set_avatar_photo_;
    bool flag_regist_;


};
#endif // MAINWINDOW_H
