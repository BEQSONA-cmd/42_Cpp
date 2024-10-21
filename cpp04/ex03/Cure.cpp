#include "Cure.hpp"

Cure::Cure()
{
    this->_type = "cure";
}

Cure::Cure(const Cure &type) : AMateria(type)
{
    this->operator=(type);
}

Cure &Cure::operator=(const Cure &type)
{
    this->_type = type._type;
    return *this;
}

Cure::~Cure(){}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}
