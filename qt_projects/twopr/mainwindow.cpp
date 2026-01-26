#include "mainwindow.h"
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    gifLabel = new QLabel(this);
    movie = new QMovie("C:/Users/Admin/Downloads/sf-dance-sf.gif");
    gifLabel->setMovie(movie);
    movie->setScaledSize(QSize(600, 600));
    movie->start();

    gifLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(gifLabel);

    textLabel = new QLabel("когда попал 3 койлами", this);
    textLabel->setStyleSheet("font-size: 32px; font-weight: bold; color: white;");
    textLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(textLabel);
}

MainWindow::~MainWindow()
{

}
