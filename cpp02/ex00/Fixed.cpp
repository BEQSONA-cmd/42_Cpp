#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
    this->value = fixed.value;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
    if(this != &fixed)
        this->value = fixed.value;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits()const
{
    std::cout << BLUE "getRawBits member function called" RESET << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << BLUE "setRawBits member function called" RESET << std::endl;
    this->value = raw;
}
