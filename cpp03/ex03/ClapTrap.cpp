#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->attak_damage = 0;
    this->energy_points = 10;
    this->hit_points = 10;
    this->name = "default";
    std::cout << YELLOW << "ClapTrap: Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
    (void)claptrap; // to avoid warning (unused parameter 'claptrap')
    std::cout << YELLOW << "ClapTrap: Copy constructor called" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
    (void)claptrap; // to avoid warning (unused parameter 'claptrap')
    std::cout << YELLOW << "ClapTrap: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << RED << "ClapTrap: Destructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->attak_damage = 0;
    this->energy_points = 10;
    this->hit_points = 10;
    this->name = name;
    std::cout << YELLOW << "ClapTrap: Default constructor called" << RESET << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if(this->hit_points <= 0 || this->energy_points <= 0)
    {
        std::cout << BLUE << this->name << RED " died" RESET<< std::endl;
        return;
    }
    this->energy_points -= 1;
    this->hit_points -= 1;
    std::cout << RED "ClapTrap " BLUE << this->name << RED" attaks " BLUE << target;
    std::cout << RED " causing " BLUE << this->attak_damage << RED " points of damage\n" RESET;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->hit_points <= 0 || this->energy_points <= 0)
    {
        std::cout << BLUE << this->name << RED " died" RESET<< std::endl;
        return;
    }
    this->energy_points -= 1;
    this->hit_points += 1;
    std::cout << RED "ClapTrap " BLUE << this->name << RED" been repaired + " GREEN << amount << RESET <<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->hit_points <= 0 || this->energy_points <= 0)
    {
        std::cout << BLUE << this->name << RED " died" RESET<< std::endl;
        return;
    }
    this->hit_points -= 1;
    std::cout << RED "ClapTrap " BLUE << this->name << RED" been Damaged - " GREEN << amount << RESET <<std::endl;
}

