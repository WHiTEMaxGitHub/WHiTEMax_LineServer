#include <iostream>
#include "Logger.h"

void Logtest() {
    Logger::debug("Hello world from Debug Log!");
    Logger::info("Hello world from Info Log!");
    Logger::warn("Hello world from Warn Log!");
    Logger::fatal("Hello world from Fatal Log!");
}

int main() {
    std::cout << "Hello world from " << __FUNCTION__ << "!" << std::endl;
    Logtest();
    return 0;
}