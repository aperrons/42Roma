#include "../headers/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(const std::string &filename) {
    loadRates(filename);
}

void BitcoinExchange::loadRates(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        float rate;

        if (std::getline(iss, date, ',') && (iss >> rate)) {
            rates[date] = rate;
        }
    }
}

float BitcoinExchange::getRate(const std::string &date) const {
    std::map<std::string, float>::const_iterator it = rates.find(date);
    if (it != rates.end()) {
        return it->second;
    }

    // Find the closest earlier date
    it = rates.lower_bound(date);
    if (it == rates.begin()) {
        throw std::runtime_error("No earlier date available in the database.");
    }

    --it;
    return it->second;
}