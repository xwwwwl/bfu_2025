#include "mainwindow.h"

#include <QApplication>
#include<QDir>
#include "QDebug"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString executableDir = QDir::;
    qDebug() << executableDir;
    return a.exec();
}
