#include "Dog.hpp"

Dog::Dog()
{
    this->brain = new Brain();
    this->type = "Dog";
    std::cout << YELLOW << "Dog: Default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
    this->operator=(dog);
    std::cout << YELLOW << "Dog: Copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*dog.brain);
    this->type = dog.type;
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
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

Brain *Dog::get_brain()
{
    return this->brain;
}