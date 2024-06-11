#include "Fixed.hpp"

int main(void)
{
    Fixed a(4.2f);
    Fixed b(5.3f);
    Fixed c(b);
    if(a < b)
        std::cout << GREEN "< operator " RESET << a << std::endl;
    else
        std::cout << b << std::endl; 
    if(b > a)
        std::cout << GREEN "> operator " RESET <<  b << std::endl;
    else
        std::cout << a << std::endl;
    if(a <= b)
        std::cout << GREEN "<= operator " RESET << a << std::endl;
    else
        std::cout << b << std::endl; 
    if(b >= a)
        std::cout << GREEN "=> operator " RESET <<  b << std::endl;
    else
        std::cout << a << std::endl;
    if(b == c)
        std::cout << GREEN "== operator " RESET << c << std::endl;
    else
        std::cout << b << std::endl; 
    if(b != a)
        std::cout << GREEN "!= operator " RESET <<  b << std::endl;
    else
        std::cout << a << std::endl;
    b = b - a;
    if(b != c)
        std::cout << GREEN "- operator " RESET << b << std::endl;
    else
        std::cout << b << std::endl;
    b = b + a;
    if(b == c)
        std::cout << GREEN "+ operator " RESET <<  b << std::endl;
    else
        std::cout << b << std::endl;
    if(b++ == c)
        std::cout << GREEN "post-increment++ operator " RESET <<  b << std::endl;
    else
        std::cout << b << std::endl;
    if(--b == c)
        std::cout << GREEN "--pre-decrement operator " RESET <<  b << std::endl;
    else
        std::cout << b << std::endl;
    if(b-- == c)
        std::cout << GREEN "post-decrement-- operator " RESET <<  b << std::endl;
    else
        std::cout << b << std::endl;
    if(++b == c)
        std::cout << GREEN "++pre-increment operator " RESET <<  b << std::endl;
    else
        std::cout << b << std::endl;
    if(a.min(a, b) == a)
        std::cout << GREEN "min function " RESET <<  a.min(a, b) << std::endl;
    if(a.max(a, b) == b)
        std::cout << GREEN "max function " RESET <<  a.max(a, b) << std::endl;
    return(0);
}

// int main(void) 
// {
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max(a, b) << std::endl;
//     return 0;
// }
