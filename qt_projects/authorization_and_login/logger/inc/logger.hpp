// logger.hpp
#pragma once

#include <QString>
#include <ctime>

class Logger {
public:
    static void info(QString message, bool debug);
    static void debug(QString message, bool debug);
    static void warning(QString message, const char* file, int line);
    static void error(QString message, const char* file, int line);
    static void fatal(QString message, const char* file, int line);
};


#ifdef NDEBUG
#define LOG_INFO(msg) Logger::info(msg, false)
#define LOG_DEBUG(msg) Logger::debug(msg, false)
#else
#define LOG_INFO(msg) Logger::info(msg, true)
#define LOG_DEBUG(msg) Logger::debug(msg, true)
#endif

#define LOG_WARNING(msg) Logger::warning(msg, __FILE__, __LINE__)
#define LOG_ERROR(msg) Logger::error(msg, __FILE__, __LINE__)
#define LOG_FATAL(msg) Logger::fatal(msg, __FILE__, __LINE__)
