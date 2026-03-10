#pragma once
#include <QString>
// #include <concepts>

// template<typename T>
// concept ILogger = requires(T logger, const QString& msg, const char* file, int line, int level) {
//     { logger.trace(msg, level) } -> std::same_as<void>;
//     { logger.debug(msg, level) } -> std::same_as<void>;
//     { logger.info(msg, level) } -> std::same_as<void>;
//     { logger.warning(msg, file, line) } -> std::same_as<void>;
//     { logger.error(msg, file, line) } -> std::same_as<void>;
//     { logger.fatal(msg, file, line) } -> std::same_as<void>;
// };

class Logger{
public:
    static void trace(const QString& message, int level);
    static void debug(const QString& message, int level);
    static void info(const QString& message, int level);
    static void warning(const QString& message, const char* file, int line);
    static void error(const QString& message, const char* file, int line);
    static void fatal(const QString& message, const char* file, int line);

};



