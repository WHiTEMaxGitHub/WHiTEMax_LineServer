#include "Logger.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <filesystem>

namespace fs = std::filesystem;

void Logger::log(LogLevel loglevel, const std::string& msg) {
    auto now = std::chrono::system_clock::now();
    auto t = std::chrono::system_clock::to_time_t(now);
    std::string timeStr = std::ctime(&t);
    if(timeStr.empty() || timeStr.back() == '\n') {
        timeStr.pop_back();
    }
    const char* color = reset_color;
    const char* level = "UNKNOWN";
    switch (loglevel) {
        case LogLevel::INFO:
            color = info_color;
            level = "INFO";
            break;
        case LogLevel::WARN:
            color = warn_color;
            level = "WARN";
            break;
        case LogLevel::FATAL:
            color = fatal_color;
            level = "FATAL";
            break;
        default:
            color = debug_color;
            level = "DEBUG";
    }
    std::cout << color << timeStr << " [" << level << "] " << reset_color << msg << std::endl;
}