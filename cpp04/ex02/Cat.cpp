#include "Cat.hpp"

Cat::Cat()
{
    this->brain = new Brain();
    this->type = "Cat";
    std::cout << YELLOW << "Cat: Default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
    this->operator=(cat);
    std::cout << YELLOW << "Cat: Copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*cat.brain);
    this->type = cat.type;
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
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

Brain *Cat::get_brain()
{
    return this->brain;
}