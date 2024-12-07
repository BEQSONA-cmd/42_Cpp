#include "PmergeMe.hpp"

bool is_duplicate(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        for (int j = i + 1; j < ac; j++)
        {
            if (std::string(av[i]) == std::string(av[j]))
                return true;
        }
    }
    return false;
}

bool is_int(std::string str)
{
    size_t i = 0;
    if(str[0] == '\0')
        return false;
    while (i < str.length())
    {
        if(str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return true;
}

Error_Type check_error(int ac, char **av)
{
    if (ac < 2)
        return NO_ARGS;
    if (ac == 2)
        return ONE_ARG;
    if (ac > MAX_ARGS)
        return TOO_MANY_ARGS;
    int i = 1;
    while (i < ac)
    {
        if (!is_int(av[i]))
            return NOT_INT;
        char *endptr;
        long num = std::strtoll(av[i], &endptr, 10);
        if (num > std::numeric_limits<int>::max() || num < 0)
            return OUT_OF_RANGE;
        i++;
    }
    if (is_duplicate(ac, av))
        return DUPLICATE;
    
    return NO_ERROR;
}

bool Error(int ac, char **av)
{
    Error_Type error = check_error(ac, av);
    switch(error)
    {
        case NO_ARGS: std::cout << GREEN "./PmergeMe " << BLUE "[args]" << RESET << std::endl; return true;
        case ONE_ARG: std::cout << RED "Please provide " << BLUE "more than 1 " << RED "argument" << RESET << std::endl; return true;
        case TOO_MANY_ARGS: std::cout << RED "Please provide " << BLUE "less than 3001" << RED "arguments" << RESET << std::endl; return true;
        case DUPLICATE: std::cout << RED "Please provide " << BLUE "unique " << RED "arguments" << RESET << std::endl; return true;
        case NOT_INT: std::cout << RED "Please provide " << BLUE "positive integers " << RED "as arguments" << RESET << std::endl; return true;
        case OUT_OF_RANGE: std::cout << RED "Please provide numbers within the " << BLUE "0 - 2147483647 " << RED "range" << RESET << std::endl; return true;
        default: return false;
    }
}
