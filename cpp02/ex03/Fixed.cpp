#include "Fixed.hpp"

// cannon
Fixed::Fixed()
{
    // std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    // std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
    this->value = fixed.value;
}

Fixed::Fixed(const int intValue)
{
    // std::cout << YELLOW "Int constructor called" RESET << std::endl;
    this->value = intValue << bits;
}

Fixed::Fixed(const float floatValue)
{
    // std::cout << YELLOW "Float constructor called" RESET << std::endl;
    this->value = roundf(floatValue * (1 << bits));
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    // std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
    if(this != &fixed)
        this->value = fixed.value;
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << RED << "Destructor called" << RESET << std::endl;
}


// fixed point number
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

float Fixed::toFloat()const
{
    float val = this->value;
    
    // end calculates the value of end 
    // by shifting 1 to the left 
    // by the number of bits stored in the bits attribute.
    int end = 1 << bits;
    // converting the fixed-point value to a floating-point value
    val = val / end;
    return(val);
}

int Fixed::toInt()const
{
    int val = this->value;

    // it shifts the bits of val to the right
    // by the number of bits stored in the bits attribute
    // converting the fixed-point value to an integer value
    int intVal = val >> bits;
    return(intVal);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return(out);
}

// operators
int Fixed::operator<(const Fixed &num) const
{
    if(this->value < num.value)
        return(1);
    return(0);
}

int Fixed::operator>(const Fixed &num) const
{ 
    if(this->value > num.value)
        return(1);
    return(0);
}

int Fixed::operator<=(Fixed &num)
{
    if(this->value <= num.value)
        return(1);
    return(0);
}

int Fixed::operator>=(Fixed &num)
{ 
    if(this->value >= num.value)
        return(1);
    return(0);
}

int Fixed::operator!=(Fixed &num)
{
    if(this->value != num.value)
        return(1);
    return(0);
}

int Fixed::operator==(Fixed &num)
{
    if(this->value == num.value)
        return(1);
    return(0);
}

Fixed Fixed::operator+(const Fixed &num) const
{
    Fixed answer;
    answer = this->toFloat() + num.toFloat();
    return(answer);
}

Fixed Fixed::operator-(const Fixed &num) const
{
    Fixed answer;
    answer = this->toFloat() - num.toFloat();
    return(answer);
}

Fixed Fixed::operator*(const Fixed &num) const
{
    Fixed answer;
    answer = this->toFloat() * num.toFloat();
    return(answer);
}

Fixed Fixed::operator/(const Fixed &num) const
{
    Fixed answer;
    answer = this->toFloat() / num.toFloat();
    return(answer);
}

Fixed Fixed::operator++()
{
    this->value++;
    return(*this);
}

Fixed Fixed::operator--()
{
    this->value--;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed answer(*this);
    ++this->value;
    return(answer);
}

Fixed Fixed::operator--(int)
{
    Fixed answer(*this);
    --this->value;
    return(answer);
}

// operations
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if(a < b)
        return(a);
    return(b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if(a > b)
        return(a);
    return(b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if(a < b)
        return(a);
    return(b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if(a > b)
        return(a);
    return(b);
}
