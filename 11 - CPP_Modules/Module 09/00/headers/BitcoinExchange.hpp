#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string &filename);
    float getRate(const std::string &date) const;

private:
    std::map<std::string, float> rates;

    void loadRates(const std::string &filename);
};

#endif