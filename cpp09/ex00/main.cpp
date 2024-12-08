#include "BitcoinExchange.hpp"

double return_price(std::multimap<std::string, double> &data, const std::string &date)
{
	double price = 0;
	std::multimap<std::string, double>::iterator it = data.find(date);

	if (it != data.end())
		price = it->second;
	else
	{
		std::multimap<std::string, double>::iterator lower = data.lower_bound(date);
		price = (--lower)->second;
	}
	return price;
}

void check_map(std::multimap<std::string, double> &data, const std::string &filename)
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
	size_t i = 0;
	while(std::getline(file, line))
	{
		if(++i == MAX_LINES){
			std::cerr << RED "Error: too many lines " RESET << std::endl; exit(1);}
		std::stringstream ss(line);
		std::getline(ss, date, delim);
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
		ss >> amount;
		if (error(data, line))
			continue;
		double price = return_price(data, date);
		std::cout << date << " => " << price * amount << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED "Error: bad input => " BLUE "usage: ./bitcoin [filename]" <<  RESET "\n";
		return (1);
	}
	std::string filename = av[1];
	std::multimap<std::string, double> data = make_data_map();
	check_map(data, filename);

	return (0);
}
