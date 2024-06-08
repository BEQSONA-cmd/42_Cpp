#include "HumanB.hpp"

HumanB::HumanB(std::string name){this->name = name; this->weapon = NULL;}

void HumanB::setWeapon(Weapon &weapon) 
{
    this->weapon = &weapon;
    std::string weaponType = this->weapon->getType();
    std::cout << GREEN << this->name << " gets a new weapon: " << weaponType << RESET << std::endl;
}

void HumanB::attack()
{
   if(this->weapon != NULL)
    {
        std::string weaponType = this->weapon->getType();
        std::cout << BLUE << this->name << " attacks with his " << weaponType << RESET << std::endl;
    }
    else
        std::cout << RED << this->name << " has no weapon to attack with" << RESET << std::endl;
}
