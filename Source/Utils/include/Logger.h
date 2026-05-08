#pragma once
#include <string>

enum class LogLevel { INFO, WARN, FATAL, DEBUG };

class Logger {
private:
    static void log(LogLevel loglevel, const std::string& msg);
    inline static const char* reset_color = "\033[0m";
public:
    inline static const char* info_color = "\033[0m";
    inline static const char* warn_color = "\033[33m";
    inline static const char* fatal_color = "\033[31m";
    inline static const char* debug_color = "\033[36m";
    inline static void info(const std::string& msg) {
        log(LogLevel::INFO, msg);
    }
    inline static void warn(const std::string& msg) {
        log(LogLevel::WARN, msg);
    }
    inline static void fatal(const std::string& msg) {
        log(LogLevel::FATAL, msg);
    }
    inline static void debug(const std::string& msg) {
        log(LogLevel::DEBUG, msg);
    }
};
