#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << YELLOW << "Cat: Default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
    this->type = cat.type;
    std::cout << YELLOW << "Cat: Copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    this->type = cat.type;
    std::cout << YELLOW << "Cat: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << RED << "Cat: Destructor called" << RESET << std::endl;
}

void Cat::makeSound() const
{
    std::cout << BLUE << "Cat: MEOW\n" << RESET << std::endl;
}

std::string Cat::getType() const
{
    return this->type;
}