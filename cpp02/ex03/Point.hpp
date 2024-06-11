#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        // default constructor
        Point();
        Point(const float n1, const float n2);
        // copy constructor
        Point(const Point &point);
        // assignment operator overload
        Point &operator=(const Point &point);
        // destructor
        ~Point();

        float getX() const;
        float getY() const;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
