#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cfloat>

enum State 
{
    IMPOSSIBLE,
    NANF,
    POSITIVE_INF,
    NEGATIVE_INF,
    CHAR,
    VALID
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &scalarconverter);
    public:
        ScalarConverter &operator=(const ScalarConverter &scalarconverter);
        ~ScalarConverter();

        static std::string convert_char(const std::string &str);
        static std::string convert_int(const std::string &str);
        static std::string convert_float(const std::string &str);
        static std::string convert_double(const std::string &str);

        static void convert(const std::string &str);
};

bool is_int(std::string str);
bool is_float(std::string str);
bool is_double(std::string str);

#endif
