#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return 1;
    }

    std::string str = av[1];
    try
    {
        ScalarConverter::convert(av[1]);
    }
    catch(const std::exception &err)
    {
        std::cerr << err.what() << '\n';
    }
    return 0;
}