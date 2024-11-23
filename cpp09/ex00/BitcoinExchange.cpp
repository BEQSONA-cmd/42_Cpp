#include "BitcoinExchange.hpp"

bool checkDateFormat(const std::string& dateString) 
{
    char dash = '-';
	if(dateString.size() != 10)
		return false;
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

bool check_valid_date(std::map<std::string, double> &data, const std::string &date)
{
	std::string first_date = data.begin()->first;
	std::string last_date = data.rbegin()->first;

	if (date < first_date || date > last_date)
		return false;

	return true;
}

int err_num(std::map<std::string, double> &data, std::string &line)
{
	if (line.empty())
		return 1;

	char delim = '|';	
	std::stringstream ss(line);
	std::string date = "";
	double amount = 0;
	std::getline(ss, date, delim);

	if (line.find(delim) == std::string::npos || line.find(delim) != line.rfind(delim))
		return 2;
	if(date.length() != 11)
		return 3;
	date.erase(date.size() - 1);
	ss >> amount;
	if (ss.fail())
		return 4;
	if(!checkDateFormat(date))
		return 5;
	if(!check_valid_date(data, date))
		return 6;
	if(amount < 0)
		return 7;
	if(amount >= 1000)
		return 8;
	return 0;
}

bool print_err(std::string error, std::string line)
{
	std::cerr << RED "Error: " << error << " => " BLUE << line <<  RESET "\n";
	return true;
}
bool error(std::map<std::string, double> &data, std::string &line)
{
	int err = err_num(data, line);
	
	switch(err)
	{
		case 1: return true;
		case 2: return print_err("bad input", line);
		case 3: return print_err("bad input", line);
		case 4: return print_err("bad input", line);
		case 5: return print_err("bad input", line);
		case 6: return print_err("date out of range", line);
		case 7: return print_err("not a positive number", line);
		case 8: return print_err("too large number", line);
		default: return false;
	}
}

std::map<std::string , double> make_data_map(void)
{
	std::string filename = "data.csv";
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
    std::getline(file, line);

	if (line != "date,exchange_rate")
	{
		std::cerr << RED "Error: bad input => " BLUE << line <<  RESET "\n";
		exit(1);
	}

	while(std::getline(file, line))
	{
		std::stringstream ss(line);
		std::getline(ss, key, ',');
		if (!checkDateFormat(key))
			std::cerr << RED "Error: bad input => " BLUE << key <<  RESET "\n";
		ss >> value;
		map[key] = value;
	}
	return map;
}

