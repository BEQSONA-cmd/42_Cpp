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

bool checkDateFormat(const std::string& dateString) 
{
    char dash = '-';
    std::stringstream ss(dateString);

    struct tm date = {};
    struct tm newDate = {};

    ss >> date.tm_year >> dash >> date.tm_mon >> dash >> date.tm_mday;
    date.tm_year -= 1900; 
    date.tm_mon -= 1;   

    newDate = date;
    mktime(&newDate);
    if (date.tm_year == newDate.tm_year && date.tm_mon == newDate.tm_mon && date.tm_mday == newDate.tm_mday)
        return true;
    return false;
}

std::map<std::string , double> make_data_map(const std::string &filename)
{
	char delim = ',';
	std::map<std::string, double> map;
	std::string key = "";
	double value = 0;

	std::ifstream file(const_cast<char *>(filename.c_str()));
	if(!file.is_open())
	{
		std::cerr << RED "Error: could not open file => " BLUE << filename <<  RESET "\n";
		exit(1);
	}
	std::string line;

	while(std::getline(file, line))
	{
		std::stringstream ss(line);
		std::getline(ss, key, delim);
		if (!checkDateFormat(key))
			std::cerr << RED "Error: bad input => " BLUE << key <<  RESET "\n";
		ss >> value;
		map[key] = value;
	}
	return map;
}

void check_map(std::map<std::string, double> &data, const std::string &filename)
{
	char delim = '|';
	std::string date = "";
	double amount = 0;

	std::ifstream file(const_cast<char *>(filename.c_str()));
	if(!file.is_open())
	{
		std::cerr << RED "Error: could not open file => " BLUE << filename <<  RESET "\n";
		exit(1);
	}
	std::string line;

	while(std::getline(file, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, delim);
		if (!checkDateFormat(date))
			std::cerr << RED "Error: bad input => " BLUE << date <<  RESET "\n";
		ss >> amount;
		if (data.find(date) != data.end())
		{
			std::cout << date << " => " << data[date] * amount << std::endl;
		}
		else
			std::cerr << RED "Error: date not found => " BLUE << date <<  RESET "\n";
		
	}
}


// data.csv
// 2009-01-11,0
// 2009-01-14,0
// 2009-01-17,0
// 2009-01-20,0
// 2009-01-23,0
// 2009-01-26,0
// 2009-01-29,0
// 2009-02-01,0
// 2009-02-04,0
// 2009-02-07,0
// input.txt
// 2011-01-03 | 3
// 2011-01-03 | 2
// 2011-01-03 | 1
// 2011-01-03 | 1.2

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	std::map<std::string, double> data = make_data_map("data.csv");
	check_map(data, "input.txt");

	return (0);
}
