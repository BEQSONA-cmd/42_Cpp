#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) 
{
    std::string weaponType = this->weapon.getType();
    std::cout << GREEN << this->name << " has a weapon: " << weaponType << RESET << std::endl;
}

void HumanA::attack()
{
    std::string weaponType = this->weapon.getType();
    std::cout << BLUE << this->name << " attacks with his " << weaponType << RESET << std::endl;
}
