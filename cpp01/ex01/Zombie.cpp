#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name) {this->name = name;}

// Default constructor
Zombie::Zombie() {}

// Destructor
Zombie::~Zombie() {std::cout << RED << this->name << " is dead" << RESET << std::endl;}

// Member function
void Zombie::announce(void)
{
    std::cout << GREEN << this->name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

