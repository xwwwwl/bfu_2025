#ifndef AUTHORIZATION_WINDOW_H
#define AUTHORIZATION_WINDOW_H


#include <QWidget>


namespace Ui {
class authorization_window;
}

class authorization_window : public QWidget
{
    Q_OBJECT

public:
    explicit authorization_window(QWidget *parent = nullptr);
    ~authorization_window();

private slots:
    void on_back_to_mainwindow_clicked();


    void on_authorization_button_clicked();

    void on_password_authorization_textChanged(const QString &arg1);

    void on_login_authorization_textChanged(const QString &arg1);

private:
    Ui::authorization_window *ui;


};

#endif // AUTHORIZATION_WINDOW_H
