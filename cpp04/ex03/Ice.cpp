#include "Ice.hpp"

Ice::Ice()
{
    this->_type = "ice";
}

Ice::Ice(const Ice &type) : AMateria(type)
{
    this->operator=(type);
}

Ice &Ice::operator=(const Ice &type)
{
    this->_type = type._type;
    return *this;
}

Ice::~Ice(){}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}
