#include <iostream>
#include "headers/RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: invalid number of arguments." << std::endl;
        return 1;
    }

    try {
        RPN rpnCalculator;
        int result = rpnCalculator.evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}