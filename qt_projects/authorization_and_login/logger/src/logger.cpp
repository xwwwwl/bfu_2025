#include "logger.hpp"
#include <QDateTime>

QString currentTime() {
    return QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
}

void Logger::info(QString message, bool debug) {
    if (debug) {
        qInfo().noquote() << "[" << currentTime() << "] [INFO] " << message;
    }
}

void Logger::debug(QString message, bool debug) {
    if (debug) {
        qDebug().noquote() << "[" << currentTime() << "] [DEBUG] " << message;
    }
}

void Logger::warning(QString message, const char* file, int line) {
    qWarning().noquote() << "[" << currentTime() << "] [WARNING] " << message
                         << "[" << file << ":" << line << "]";
}

void Logger::error(QString message, const char* file, int line) {
    qCritical().noquote() << "[" << currentTime() << "] [ERROR] " << message
                          << "[" << file << ":" << line << "]";
}

void Logger::fatal(QString message, const char* file, int line) {
    qFatal().noquote() << "[" << currentTime() << "] [FATAL] " << message
                          << "[" << file << ":" << line << "]";

}
