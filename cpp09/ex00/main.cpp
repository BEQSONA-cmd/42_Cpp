#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

bool checkDateFormat(const std::string& dateString) 
{

    char dash;
    std::stringstream ss(dateString);

    struct tm date;
    struct tm newDate;

    ss >> date.tm_year >> dash >> date.tm_mon >> dash >> date.tm_mday;
    date.tm_year -= 1900; date.tm_mon -= 1;
    date.tm_hour = 1;            // Hour
    date.tm_min = 0;             // Minute
    date.tm_sec = 0;             // Second    

    newDate = date;

	mktime(&newDate);
	
	if (newDate.tm_year == date.tm_year && newDate.tm_mon == date.tm_mon && newDate.tm_mday == date.tm_mday)
		return true;
	return false;
}

std::map<std::string , double> make_map(const std::string &filename, char delim)
{
	std::map<std::string, double> map;
	(void)delim;

	std::ifstream file(const_cast<char *>(filename.c_str()));
	if(!file.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		exit(1);
	}
	std::string line;

	while(std::getline(file, line))
	{
		std::cout << line << std::endl;
	}
	return map;
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

	std::map<std::string, double> data = make_map("data.csv", ',');
	std::map<std::string, double> input = make_map("input.txt", '|');

	BitcoinExchange bitcoinexchange(data, input);

	return (0);
}
