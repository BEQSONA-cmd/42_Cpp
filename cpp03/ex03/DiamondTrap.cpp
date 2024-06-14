#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    this->name = "Default";
    ClapTrap::name = "ClapTrap Default";
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attak_damage = FragTrap::attak_damage;
    std::cout << YELLOW << "DiamondTrap: Default constructor called" << RESET << std::endl;

}

DiamondTrap::DiamondTrap(std::string name)
{
    this->name = name;
    ClapTrap::name = "ClapTrap " + name;
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attak_damage = FragTrap::attak_damage;
    std::cout << YELLOW << "DiamondTrap: Default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap)
{
    this->name = diamondtrap.name;
    ClapTrap::name = diamondtrap.name;
    this->hit_points = diamondtrap.hit_points;
    this->energy_points = diamondtrap.energy_points;
    this->attak_damage = diamondtrap.attak_damage;
    std::cout << YELLOW << "DiamondTrap: Copy constructor called" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
    this->name = diamondtrap.name;
    ClapTrap::name = diamondtrap.name;
    this->hit_points = diamondtrap.hit_points;
    this->energy_points = diamondtrap.energy_points;
    this->attak_damage = diamondtrap.attak_damage;
    std::cout << YELLOW << "DiamondTrap: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED << "DiamondTrap: Destructor called" << RESET << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << GREEN "I am a: " BLUE << this->name << RESET << std::endl;
    std::cout << GREEN "I am from: " BLUE << ClapTrap::name << RESET << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

int DiamondTrap::getHitPoints()
{
    return this->hit_points;
}

int DiamondTrap::getEnergyPoints()
{
    return this->energy_points;
}

int DiamondTrap::getAttackDamage()
{
    return this->attak_damage;
}


