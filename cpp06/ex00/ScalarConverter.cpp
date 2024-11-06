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
    std::string converted_str = "";

    if (is_int(str))
        converted_str = str;
    else if (is_double(str))
        converted_str = str;
    else if (is_float(str))
        converted_str = str.substr(0, str.length() - 1);
    else if (str.length() == 1)
        converted_str = str;
    else
        converted_str = "impossible";

    std::string char_str = convert_char(converted_str);
    std::string int_str = convert_int(converted_str);
    std::string float_str = convert_float(converted_str);
    std::string double_str = convert_double(converted_str);

    std::cout << "char: " << char_str << std::endl;
    std::cout << "int: " << int_str << std::endl;
    std::cout << "float: " << float_str << std::endl;
    std::cout << "double: " << double_str << std::endl;
}
 