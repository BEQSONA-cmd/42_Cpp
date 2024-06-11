#ifndef FIXED_HPP
#define FIXED_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
    private:
        int value;
        static const int bits = 8;
    public:
        // default constructor
        Fixed();
        // copy constructor
        Fixed(const Fixed &fixed);
        // assignment operator overload
        Fixed &operator=(const Fixed &fixed);
        // destructor
        ~Fixed();

        // fixed point number
        int getRawBits()const;
        void setRawBits(int const raw);
        Fixed(const int intValue);
        Fixed(const float floatValue);
        float toFloat()const;
        int toInt()const;

        // operators
        int operator<(const Fixed &num) const;
        int operator>(const Fixed &num) const;
        int operator<=(Fixed &num);
        int operator>=(Fixed &num);
        int operator!=(Fixed &num);
        int operator==(Fixed &num);

        // arithmetic operators
        Fixed operator+(const Fixed &num) const;
        Fixed operator-(const Fixed &num) const;
        Fixed operator*(const Fixed &num) const;
        Fixed operator/(const Fixed &num) const;
        Fixed operator++();
        Fixed operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        // public overloaded member functions
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        const static Fixed &min(const Fixed &a, const Fixed &b);
        const static Fixed &max(const Fixed &a, const Fixed &b);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
