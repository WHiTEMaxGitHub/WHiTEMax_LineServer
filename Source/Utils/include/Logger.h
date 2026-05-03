#pragma once
#include <string>

enum class LogLevel { INFO, WARN, FATAL, DEBUG };

class Logger {
private:
    static void log(LogLevel loglevel, const std::string& msg);
    inline static const char* colors[] = {
        "\033[0m", 
        "\033[33m",
        "\033[31m",
        "\033[36m"
    };
    inline static const char* reset_color = "\033[0m";
public:
    inline static const char* const& info_color = colors[0];
    inline static const char* const& warn_color = colors[1];
    inline static const char* const& fatal_color = colors[2];
    inline static const char* const& debug_color = colors[3];
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
