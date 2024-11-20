#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->name = "default";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attak_damage = 20;
    // std::cout << YELLOW << "ScavTrap: Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attak_damage = 20;
    // std::cout << YELLOW << "ScavTrap: Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
    this->name = scavtrap.name;
    this->hit_points = scavtrap.hit_points;
    this->energy_points = scavtrap.energy_points;
    this->attak_damage = scavtrap.attak_damage;
    // std::cout << YELLOW << "ScavTrap: Copy constructor called" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
    this->name = scavtrap.name;
    this->hit_points = scavtrap.hit_points;
    this->energy_points = scavtrap.energy_points;
    this->attak_damage = scavtrap.attak_damage;
    // std::cout << YELLOW << "ScavTrap: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    // std::cout << RED << "ScavTrap: Destructor called" << RESET << std::endl;
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
    std::cout << RED "energy points: " BLUE << this->energy_points << RESET << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << RED "ScavTrap " BLUE << this->name << RED " is in Gate Keeper mode (BUT WHY?)\n" RESET;
}
