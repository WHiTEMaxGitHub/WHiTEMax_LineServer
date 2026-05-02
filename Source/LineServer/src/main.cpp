#include <iostream>
#include "Logger.h"
int main() {
    std::cout << "Hello world from " << __FUNCTION__ << "!" << std::endl;
    say_hello();
    return 0;
}