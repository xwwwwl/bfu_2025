#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, bool flag_regist=0);
    ~MainWindow();

private slots:
    void on_go_to_authorization_windows_clicked();

    void on_go_to_registration_windows_clicked();

private:
    Ui::MainWindow *ui;

    bool flag_regist_;


};
#endif // MAINWINDOW_H
