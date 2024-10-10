#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << YELLOW << "Dog: Default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
    this->type = dog.type;
    std::cout << YELLOW << "Dog: Copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    this->type = dog.type;
    std::cout << YELLOW << "Dog: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << RED << "Dog: Destructor called" << RESET << std::endl;
}

void Dog::makeSound() const
{
    std::cout << BLUE << "Dog: WOOF\n" << RESET << std::endl;
}

std::string Dog::getType() const
{
    return this->type;
}