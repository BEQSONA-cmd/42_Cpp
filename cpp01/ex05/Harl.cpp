#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << BLUE << "AGGRESSIVE DEBUGGING !!!" << RESET << std::endl;
}

void Harl::info(void)
{
    std::cout << GREEN << "GENERAL INFORMATION !!!" << RESET << std::endl;
}

void Harl::warning(void)
{
    std::cout << YELLOW << "BE CAREFUL WARNING !!!" << RESET << std::endl;
}

void Harl::error(void)
{
    std::cout << RED << "ERROR ERROR ERROR !!!" << RESET << std::endl;
}

int Harl::get_level(std::string level)
{
    if(level == "debug") return(1);
    if(level == "info") return(2);
    if(level == "warning") return(3);
    if(level == "error") return(4);
    return(0);
}

void Harl::complain(std::string level)
{
    std::string arr[4] = {"debug", "info", "warning", "error"};
    void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int num = get_level(level);
    if (num == 0)
        std::cout << RED << "There is no such level as: " << level << RESET << std::endl;
    else
        (this->*func[num - 1])();
}
