#include "Harl.hpp"

std::string ft_tolower(std::string s)
{
    std::string str = s;
    int i = 0;
    while (str[i])
    {
        str[i] = std::tolower(str[i]);
        i++;
    }
    return (str);
}

int main(int ac, char **av)
{
    Harl harl;
    if(ac != 2)
    {
        std::cout << RED "Usage: ./harlFilter [LEVEL]" RESET << std::endl;
        return(0);
    }
    std::string level = ft_tolower(av[1]);
    harl.complain(level);
    return (0);
}
