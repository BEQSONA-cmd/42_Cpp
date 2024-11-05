#include "ScalarConverter.hpp"

// char ft_char_atoi(int n)
// {
//     char c = 0;
//     if (n >= 0 && n <= 127)
//         c = static_cast<char>(n);
//     return c;
// }

int ft_atoi(const std::string str)
{
    size_t i = 0;
    int res = 0;
    bool is_negative = false;

    if (str[i] == '-')
    {
        is_negative = true;
        i++;
    }

    while (i < str.length())
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;

        if (str[i] >= '0' && str[i] <= '9')
            res = res * 10 + str[i] - '0';
        i++;
    }

    if (is_negative)
        res = res * -1;
    return res;
}

// float convert
float ft_parse_integer_part(const std::string &str, size_t *i, int *sign)
{
    float res = 0;
    *sign = 1;
    if (str[*i] == '-')
    {
        *sign = -1;
        (*i)++;
    }
    while (str[*i] != '.' && str[*i] != '\0' && str[*i] != '\n')
    {
        res = res * 10 + str[*i] - '0';
        (*i)++;
    }
    return res;
}

float ft_parse_decimal_part(const std::string &str, size_t i)
{
    float dec = 0;
    int j = 0;
    if (str[i] == '.')
    {
        i++;
        while (i < str.length() && str[i] != '\0' && str[i] != '\n')
        {
            dec = dec * 10 + str[i] - '0';
            i++;
            j++;
        }
    }
    while (j > 0)
    {
        dec = dec / 10;
        j--;
    }
    return dec;
}

float ft_float_atoi(const std::string &str)
{
    float res;
    float dec;
    size_t i = 0;
    int sign = 1;

    res = ft_parse_integer_part(str, &i, &sign);
    dec = ft_parse_decimal_part(str, i);
    return sign * (res + dec);
}
