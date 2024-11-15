#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <algorithm>
#include <iostream>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> data;
        std::map<std::string, double> input;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &bitcoinexchange);
        BitcoinExchange &operator=(const BitcoinExchange &bitcoinexchange);
        ~BitcoinExchange();

        BitcoinExchange(std::map<std::string, double> &data, std::map<std::string, double> &input);
};

#endif
