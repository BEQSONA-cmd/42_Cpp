#include "Point.hpp"

Point::Point(): x(0), y(0)
{
    // std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Point::Point(const float n1, const float n2): x(n1), y(n2)
{
}

Point::Point(const Point &point): x(point.x), y(point.y)
{
    // std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
}

Point &Point::operator=(const Point &point)
{
    if(this == &point)
        return(*this);
    return *this;
}

Point::~Point()
{
    // std::cout << RED << "Destructor called" << RESET << std::endl;
}

float Point::getX() const
{
    return x.toFloat();
}

float Point::getY() const
{
    return y.toFloat();
}
