#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << CYAN << "[ DEBUG ]" RESET << std::endl;
    std::cout << BLUE << "AGGRESSIVE DEBUGGING !!!\n" << RESET << std::endl;
}

void Harl::info(void)
{
    std::cout << CYAN << "[ INFO ]" RESET << std::endl;
    std::cout << GREEN << "GENERAL INFORMATION !!!\n" << RESET << std::endl;
}

void Harl::warning(void)
{
    std::cout << CYAN << "[ WARNING ]" RESET << std::endl;
    std::cout << YELLOW << "BE CAREFUL WARNING !!!\n" << RESET << std::endl;
}

void Harl::error(void)
{
    std::cout << CYAN << "[ ERROR ]" RESET << std::endl;
    std::cout << RED << "ERROR ERROR ERROR !!!\n" << RESET << std::endl;
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
    {
        std::cout << RED "There is no such level as: " << level << RESET << std::endl;
        return;
    }
    while (num <= 4)
    {
        switch (num)
        {
            case 1: (this->*func[0])(); break;
            case 2: (this->*func[1])(); break;
            case 3: (this->*func[2])(); break;
            case 4: (this->*func[3])(); break;
        }
        num++;
    }
}
