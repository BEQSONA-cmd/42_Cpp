#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << RED "Error: bad input => " BLUE "usage: ./rpn 'arguments'" << RESET "\n";
        return (1);
    }
    std::string arguments = av[1];

    try {
        RPN::calculate(arguments);
    } catch (std::exception &e){
        std::cerr << e.what() << RESET "\n";
    }
    
    return 0;
}