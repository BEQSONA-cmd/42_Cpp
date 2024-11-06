#include "ScalarConverter.hpp"

bool ft_strcmp(std::string str1, std::string str2)
{
    size_t i = 0;

    if(str1.length() != str2.length())
        return false;

    while(i < str1.length())
    {
        if(str1[i] != str2[i])
            return false;
        i++;
    }
    return true;
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
    int f = 0;

    if (str[i] == '-')
        i++;
    while (i < str.length())
    {
        if (str[i] == '.')
        {
            dot++;
            i++;
        }
        if (str[i] == 'f')
        {
            f++;
            i++;
            if(str[i] != '\0')
                return false;
            break;
        }
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    if (f == 1 && str.length() > 1)
    {
        char *endptr;
        float valid = std::strtof(str.c_str(), &endptr);
        if (valid >= -FLT_MAX && valid <= FLT_MAX)
            return true;
    }
    return false;
}

bool is_double(std::string str)
{
    size_t i = 0;

    int dot = 0;
    if (str[i] == '-')
        i++;
    while (i < str.length())
    {
        if (str[i] == '.')
        {
            dot++;
            if (dot > 1)
                return false;
            i++;
        }
        if ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
            return false;
        i++;
    }
    if (dot == 1)
        return true;
    return false;
}

template <typename T>

State determine_state(T n, const std::string &str, char *endptr)
{
    if (std::isnan(n) && (ft_strcmp(str, "nanf") || ft_strcmp(str, "nan")))
        return NANF;
    if (std::isinf(n))
    {
        if (n > 0 && (ft_strcmp(str, "+inff") || ft_strcmp(str, "+inf") || ft_strcmp(str, "inff") || ft_strcmp(str, "inf")))
            return POSITIVE_INF;
        else if (n < 0 && (ft_strcmp(str, "-inff") || ft_strcmp(str, "-inf")))
            return NEGATIVE_INF;
    }
    else if(is_int(str) || is_float(str) || is_double(str))
        return VALID;
    else if(str.length() == 1)
        return CHAR;
    else if (endptr == str.c_str())
        return IMPOSSIBLE;
    return IMPOSSIBLE;
}

std::string char_to_int_to_str(const std::string &str)
{
    std::stringstream ss;
    ss << static_cast<int>(str[0]);
    return ss.str();
}

std::string ScalarConverter::convert_char(const std::string &str)
{
    char c;

    if(is_int(str) || is_float(str) || is_double(str))
    {
        long long str_int;
        char *endptr;
        str_int = std::strtol(str.c_str(), &endptr, 10);
        if(str_int >= -128 && str_int < 128)
        {
            c = static_cast<char>(str_int);
            if(c >= 32 && c <= 126)
                return "'" + std::string(1, c) + "'";
            else
                return "Non displayable";
        }
        else
            return "impossible";
    }
    else if(str.length() == 1)
        return "'" + str + "'";
    else
        return "impossible";
}

std::string ScalarConverter::convert_int(const std::string &str)
{
    long long i;
    char *endptr;
    i = std::strtol(str.c_str(), &endptr, 10);

    std::string converted_str;

    if ((is_int(str) || is_float(str) || is_double(str)) && i >= INT_MIN && i <= INT_MAX)
    {
        std::stringstream ss;
        ss << i;
        converted_str = ss.str();
    } 
    else if (str.length() == 1)
        converted_str = char_to_int_to_str(str);
    else
        converted_str = "impossible";
    
    return converted_str;
}

std::string ScalarConverter::convert_float(const std::string &str)
{
    float f;
    char *endptr;
    f = std::strtof(str.c_str(), &endptr);

    State state = determine_state(f, str, endptr);
    
    switch (state)
    {
        case IMPOSSIBLE: return ("impossible");
        case NANF: return ("nanf");
        case POSITIVE_INF: return ("+inff");
        case NEGATIVE_INF: return ("-inff");
        case CHAR: return (char_to_int_to_str(str) + ".0f");
        case VALID:
            std::stringstream ss;
            if ((std::fabs(f) >= 1e6 || std::fabs(f) < 1e-3) && f != 0)
                ss << std::scientific << std::setprecision(5) << f << "f";
            else
                ss << std::fixed << std::setprecision(1) << f << "f";
            return (ss.str());
    }
    return ("impossible");
}


std::string ScalarConverter::convert_double(const std::string &str)
{
    double d;
    char *endptr;
    d = std::strtod(str.c_str(), &endptr);

    State state = determine_state(d, str, endptr);
    
    switch (state)
    {
        case IMPOSSIBLE: return ("impossible");
        case NANF: return ("nan");
        case POSITIVE_INF: return ("+inf");
        case NEGATIVE_INF: return ("-inf");
        case CHAR: return (char_to_int_to_str(str) + ".0");
        case VALID:
            std::stringstream ss;
            if ((std::fabs(d) >= 1e6 || std::fabs(d) < 1e-3) && d != 0)
                ss << std::scientific << std::setprecision(5) << d;
            else
                ss << std::fixed << std::setprecision(1) << d;
            return (ss.str());
    }
    return ("impossible");
}