#include "BitcoinExchange.hpp"

double return_price(std::map<std::string, double> &data, const std::string &date)
{
	double price = 0;
	std::map<std::string, double>::iterator it = data.find(date);

	if (it != data.end())
		price = it->second;
	else
	{
		std::map<std::string, double>::iterator lower = data.lower_bound(date);
		price = (--lower)->second;
	}
	return price;
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
	std::getline(file, line);

	if (line != "date | value")
	{
		std::cerr << RED "Error: bad input => " BLUE << line <<  RESET "\n";
		exit(1);
	}

	while(std::getline(file, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, delim);
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
		ss >> amount;
		if (error(data, date, amount))
			continue;
		double price = return_price(data, date);
		std::cout << date << " => " << price * amount << std::endl;
	}
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	std::map<std::string, double> data = make_data_map();
	check_map(data, "input.txt");

	return (0);
}
