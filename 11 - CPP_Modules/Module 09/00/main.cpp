#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "headers/BitcoinExchange.hpp"

void printError(const std::string &message) {
    std::cerr << "Error: " << message << std::endl;
}

bool isValidDate(const std::string &date) {
    // Simple validation for the date format: YYYY-MM-DD
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    // Further checks can be added for proper date validation
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printError("could not open file.");
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        printError("could not open file.");
        return 1;
    }

    BitcoinExchange exchange("data.csv");

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string date;
        char separator;
        float value;

        if (!(iss >> date >> separator >> value) || separator != '|') {
            printError("bad input => " + line);
            continue;
        }

        if (!isValidDate(date)) {
            printError("bad input => " + date);
            continue;
        }

        if (value < 0) {
            printError("not a positive number.");
            continue;
        }

        if (value > 1000) {
            printError("too large a number.");
            continue;
        }

        try {
            float rate = exchange.getRate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        } catch (const std::exception &e) {
            printError(e.what());
        }
    }

    return 0;
}
