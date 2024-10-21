#include "AMateria.hpp"

AMateria::AMateria()
{
    this->_type = "AMateria";
}

AMateria::AMateria(const AMateria &type)
{
    this->operator=(type);
}

AMateria &AMateria::operator=(const AMateria &type)
{
    this->_type = type._type;
    return *this;
}

AMateria::~AMateria(){}

std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    if(this->_type == "ice")
        std::cout << RED << "* shoots an ice bolt at " BLUE << target.getName() << RED " *" << RESET << std::endl;
    else if(this->_type == "cure")
        std::cout << GREEN << "* heals " BLUE << target.getName() << GREEN "'s wounds *" << RESET << std::endl;
}
