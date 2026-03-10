#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <logger.hpp>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    #ifdef QT_NO_DEBUG
        _level=10;
        qDebug() << "RELEASE BUILD";
    #else

        qDebug() << "DEBUG BUILD";
    #endif

    Logger::info("programm start",_level);
}

MainWindow::~MainWindow()
{
    Logger::info("programm end",_level);
    delete ui;
}




void MainWindow::on_runtime_error_button_clicked()
{
    Logger::info(">>> on_runtime_error_button_clicked() started",_level);

    bool ok_number_1;
    Logger::trace("объявлена переменная bool ok_number_1 (пока без значения)",_level);

    int number_1 = ui->number_1->text().toInt(&ok_number_1);
    Logger::trace(QString("преобразование text -> int для number_1, ok_number_1 = %1").arg(QString::number(ok_number_1)),_level);
    Logger::debug(QString("number_1 = %1").arg(QString::number(number_1)),_level);
    Logger::debug(QString("ok_number_1 = %1").arg(QString::number(ok_number_1)),_level);
    bool ok_number_2;
    Logger::trace("объявлена переменная bool ok_number_2 (пока без значения)",_level);


    int number_2 = ui->number_2->text().toInt(&ok_number_2);
    Logger::trace(QString("преобразование text -> int для number_2, ok_number_2 = %1").arg(QString::number(ok_number_2)),_level);
    Logger::debug(QString("number_2 = %1").arg(QString::number(number_2)),_level);
    Logger::debug(QString("ok_number_2 = %1").arg(QString::number(ok_number_1)),_level);
    if (ok_number_1) {
        Logger::trace("Вход в if",_level);

        Logger::trace("ok_number_1 = true -> число введено корректно",_level);
    }
    else {
        Logger::error("enter a variable of type int", __FILE__, __LINE__);
        ui->result->setText("Error: enter a variable of type int");
        Logger::trace("ok_number_1 = false -> ошибка ввода number_1",_level);
    }

    if (ok_number_2) {
        Logger::trace("Вход в if",_level);
        Logger::trace("ok_number_2 = true -> число введено корректно",_level);
    }
    else {
        Logger::trace("Вход в else",_level);
        Logger::error("enter a variable of type int", __FILE__, __LINE__);
        ui->result->setText("Error: enter a variable of type int");
        Logger::trace("ok_number_2 = false -> ошибка ввода number_2",_level);
    }

    if (ok_number_1 && ok_number_2) {
        Logger::trace("Вход в if",_level);
        Logger::trace("оба числа введены корректно, проверяем деление на 0",_level);

        if (number_2 == 0) {
            Logger::trace("Вход в if",_level);
            Logger::error("cannot be divided by 0", __FILE__, __LINE__);
            ui->result->setText("Error: cannot be divided by 0");
            Logger::trace("number_2 = 0 -> деление невозможно",_level);
        }
        else {
            Logger::trace("Вход в else",_level);
            Logger::trace(QString("выполняем деление %1 / %2").arg(number_1).arg(number_2),_level);
            if (number_1%number_2!=0){
                Logger::warning("деление не нацело", __FILE__, __LINE__);
            }
            int result = number_1 / number_2;
            Logger::debug(QString("result = %1").arg(QString::number(result)),_level);
            QString result_str = QString::number(result);
            ui->result->setText(result_str);

            Logger::trace("результат успешно получен и выведен",_level);
            Logger::trace(QString("result = %1").arg(QString::number(result)),_level);
        }
    }
    else {
        Logger::trace("Вход в else",_level);
        Logger::trace("пропускаем деление: одно из чисел не прошло валидацию",_level);
    }

    Logger::info("<<< on_runtime_error_button_clicked() finished",_level);
}

void MainWindow::on_self_destruction_button_clicked()
{
    Logger::fatal("вы нажали на кнопку самоуничтожения", __FILE__, __LINE__);
}

