#include "Ice.hpp"

Ice::Ice()
{
    this->_type = "ice";
    std::cout << YELLOW << "Ice: Default constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice &type) : AMateria(type)
{
    this->operator=(type);
    std::cout << YELLOW << "Ice: Copy constructor called" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &type)
{
    this->_type = type._type;
    std::cout << YELLOW << "Ice: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

Ice::~Ice()
{
    std::cout << RED << "Ice: Destructor called" << RESET << std::endl;
}

AMateria *Ice::clone() const
{
    delete this;
    Ice *new_ice = new Ice();
    return new_ice;
}

std::string const & Ice::getType() const
{
    return this->_type;
}
