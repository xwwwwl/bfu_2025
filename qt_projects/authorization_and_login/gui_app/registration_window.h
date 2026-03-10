#ifndef REGISTRATION_WINDOW_H
#define REGISTRATION_WINDOW_H

#include <QDialog>

QString encoder(QString password, int key);
namespace Ui {
class registration_window;
}

class registration_window : public QDialog
{
    Q_OBJECT

public:
    explicit registration_window(QWidget *parent = nullptr);
    ~registration_window();

private slots:
    void on_back_to_mainwindow_clicked();

    void on_registration_button_clicked();

    void on_password_registration_textChanged(const QString &arg1);

    void on_login_registration_textChanged(const QString &arg1);

private:
    Ui::registration_window *ui;
    bool password_correct = true;
};

#endif // REGISTRATION_WINDOW_H
