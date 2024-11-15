#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinexchange)
{
    *this = bitcoinexchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinexchange)
{
    (void)bitcoinexchange;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::map<std::string, double> &data, std::map<std::string, double> &input)
{
    (void)data;
    (void)input;
}