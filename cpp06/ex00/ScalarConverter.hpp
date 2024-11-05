#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include <string>

class ScalarConverter
{
    private:

    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &scalarconverter);
        ScalarConverter &operator=(const ScalarConverter &scalarconverter);
        ~ScalarConverter();

        static void convert(const std::string &str);
};

// concert

int ft_atoi(std::string str);
char ft_char_atoi(int n);
float ft_float_atoi(const std::string &str);

// print

void print_char(std::string str);
void print_int(std::string str);
void print_float(std::string str);
void print_double(std::string str);



#endif
