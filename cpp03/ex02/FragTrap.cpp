#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->name = "default";
    this->hit_points = 100;
    this->energy_points = 100;
    this->attak_damage = 30;
    std::cout << YELLOW << "FragTrap: Default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attak_damage = 30;
    std::cout << YELLOW << "FragTrap: Default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap)
{
    (void)fragtrap; // to avoid warning (unused parameter 'fragtrap')
    std::cout << YELLOW << "FragTrap: Copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
    (void)fragtrap; // to avoid warning (unused parameter 'fragtrap')
    std::cout << YELLOW << "FragTrap: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << RED << "FragTrap: Destructor called" << RESET << std::endl;
}


void FragTrap::highFivesGuys()
{
    std::cout << BLUE << this->name << GREEN " +++ asks guys to highFive +++\n"; 
}