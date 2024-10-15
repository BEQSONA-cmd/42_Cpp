#include "AMateria.hpp"

AMateria::AMateria()
{
    this->_type = "AMateria";
    std::cout << YELLOW << "AMateria: Default constructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria &type)
{
    this->operator=(type);
    std::cout << YELLOW << "AMateria: Copy constructor called" << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &type)
{
    this->_type = type._type;
    std::cout << YELLOW << "AMateria: Copy assignment operator called" << RESET << std::endl;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << RED << "AMateria: Destructor called" << RESET << std::endl;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}
