#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    std::cout << YELLOW << "Animal: Default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &animal)
{
    this->type = animal.type;
    std::cout << YELLOW << "Animal: Copy constructor called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
    this->type = animal.type;
    std::cout << YELLOW << "Animal: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << RED << "Animal: Destructor called" << RESET << std::endl;
}

void Animal::makeSound() const
{
    std::cout << BLUE << "Animal: Animaly sound\n" << RESET << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}