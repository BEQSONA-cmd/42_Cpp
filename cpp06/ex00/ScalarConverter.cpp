#include "ScalarConverter.hpp"

// ScalarConverter

ScalarConverter::ScalarConverter()
{
    std::cout << YELLOW << "ScalarConverter created" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarconverter)
{
    (void)scalarconverter;
    std::cout << YELLOW << "ScalarConverter created" << RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalarconverter)
{
    (void)scalarconverter;
    std::cout << YELLOW << "ScalarConverter created" << RESET << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << YELLOW << "ScalarConverter destroyed" << RESET << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    std::string char_str = convert_char(str);
    std::string int_str = convert_int(str);
    std::string float_str = convert_float(str);
    std::string double_str = convert_double(str);

    std::cout << "char: " << char_str << std::endl;
    std::cout << "int: " << int_str << std::endl;
    std::cout << "float: " << float_str << std::endl;
    std::cout << "double: " << double_str << std::endl;
}
 