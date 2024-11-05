#include "ScalarConverter.hpp"

// is check
bool is_print(char c)
{
    if(c != ' ' && c != '\t' && c != '\n' && c != '\0' && c != '\r' && c != '\v' && c != '\f')
        return true;
    return false;
}

bool is_char(std::string str)
{
    char c;
    int string = ft_atoi(str);
    c = static_cast<char>(string);
    std::cout << "char: " << c << std::endl;
    if (is_print(c))
        return true;
    return false;
}

bool is_int(std::string str)
{
    size_t i = 0;
    if (str[i] == '-')
        i++;
    while (i < str.length())
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return true;
}

bool is_float(std::string str)
{
    size_t i = 0;
    int dot = 0;
    if (str[i] == '-')
        i++;
    while (i < str.length())
    {
        if (str[i] == '.')
            dot++;
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    if (dot == 1)
        return true;
    return false;
}

void print_char(std::string str)
{
    char c = str[0];
    std::cout << "char: ";
    if (is_char(str))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void print_int(std::string str)
{
    int i = ft_atoi(str);
    std::cout << "int: " << i << std::endl;
}

void print_float(std::string str)
{
    float f = ft_float_atoi(str);
    std::cout << "float: " << f << "f" << std::endl;
}

void print_double(std::string str)
{
    float d = ft_float_atoi(str);
    std::cout << "double: " << d << std::endl;
}

