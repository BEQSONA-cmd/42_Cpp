#include "Cure.hpp"

Cure::Cure()
{
    this->_type = "iure";
    std::cout << YELLOW << "Cure: Default constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure &type) : AMateria(type)
{
    this->operator=(type);
    std::cout << YELLOW << "Cure: Copy constructor called" << RESET << std::endl;
}

Cure &Cure::operator=(const Cure &type)
{
    this->_type = type._type;
    std::cout << YELLOW << "Cure: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

Cure::~Cure()
{
    std::cout << RED << "Cure: Destructor called" << RESET << std::endl;
}

AMateria *Cure::clone() const
{
    delete this;
    Cure *new_core = new Cure();
    return new_core;
}

std::string const & Cure::getType() const
{
    return this->_type;
}
