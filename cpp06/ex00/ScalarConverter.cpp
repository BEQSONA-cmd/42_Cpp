#include "ScalarConverter.hpp"

// ScalarConverter

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarconverter)
{
    *this = scalarconverter;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalarconverter)
{
    (void)scalarconverter;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &str)
{
    print_char(str);
    print_int(str);
    print_float(str);
    print_double(str);
}
 