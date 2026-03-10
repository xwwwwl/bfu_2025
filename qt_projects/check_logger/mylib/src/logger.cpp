#include <logger.hpp>
#include <QString>
#include <QDateTime>
#include <QDebug>


void Logger::trace(const QString& message, int level) {
    if (level==1){
        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        QString logEntry = QString("[%1] [TRACE] %2").arg(timestamp, message);

        qDebug().noquote() << logEntry;
    }

}
void Logger::debug(const QString& message, int level) {
    if (level==2){
            QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
            QString logEntry = QString("[%1] [DEBUG] %2").arg(timestamp, message);

            qDebug().noquote() << logEntry;
        }

}
void Logger::info(const QString& message, int level) {
    if (level==3){
        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        QString logEntry = QString("[%1] [INFO] %2").arg(timestamp, message);

        qInfo().noquote() << logEntry;
    }

}
void Logger::warning(const QString& message, const char* file, int line) {

    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    QString fullPath = QString(file);
    int index = fullPath.indexOf("big_project/");
    QString path = fullPath.mid(index);
    QString logEntry = QString("[%1] [WARNING] [%2 : %3] %4")
                           .arg(timestamp).arg(path).arg(line).arg(message);

    qWarning().noquote() << logEntry;

}

void Logger::error(const QString& message, const char* file, int line) {

        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        QString fullPath = QString(file);
        int index = fullPath.indexOf("big_project/");
        QString path = fullPath.mid(index);
        QString logEntry = QString("[%1] [ERROR] [%2 : %3] %4")
                               .arg(timestamp).arg(path).arg(line).arg(message);

        qCritical().noquote() << logEntry;


}
void Logger::fatal(const QString& message, const char* file, int line) {

    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    QString fullPath = QString(file);
    int index = fullPath.indexOf("big_project/");
    QString path = fullPath.mid(index);
    QString logEntry = QString("[%1] [FATAL] [%2 : %3] %4")
                           .arg(timestamp).arg(path).arg(line).arg(message);

    qFatal().noquote() << logEntry;

}
