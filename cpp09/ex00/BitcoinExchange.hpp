#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"
#include <algorithm>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

#define MAX_LINES 100

std::multimap<std::string , double> make_data_map(void);
bool error(std::multimap<std::string, double> &data, std::string &line);

#endif
