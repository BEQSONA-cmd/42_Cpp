#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->name = "default";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attak_damage = 20;
    std::cout << YELLOW << "ScavTrap: Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attak_damage = 20;
    std::cout << YELLOW << "ScavTrap: Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
    (void)scavtrap; // to avoid warning (unused parameter 'scavtrap')
    std::cout << YELLOW << "ScavTrap: Copy constructor called" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
    (void)scavtrap; // to avoid warning (unused parameter 'scavtrap')
    std::cout << YELLOW << "ScavTrap: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << RED << "ScavTrap: Destructor called" << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if(this->hit_points <= 0 || this->energy_points <= 0)
    {
        std::cout << BLUE << this->name << RED " died" RESET<< std::endl;
        return;
    }
    this->energy_points -= 1;
    this->hit_points -= 1;
    std::cout << RED "ScavTrap " BLUE << this->name << RED" attaks " BLUE << target;
    std::cout << RED " causing " BLUE << this->attak_damage << RED " points of damage\n" RESET;
}

void ScavTrap::guardGate()
{
    std::cout << RED "ScavTrap " BLUE << this->name << RED " is in Gate Keeper mode (BUT WHY?)\n" RESET;
}
