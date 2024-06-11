#include "Fixed.hpp"

int main(void)
{
    Fixed a(3.14f);
    int rawBits = a.getRawBits();
    std::cout << BLUE "Raw bits of a: " RESET << rawBits << std::endl;
    float floatResult = a.toFloat();
    std::cout << BLUE "a as float: " RESET << floatResult << std::endl;
    int intResult = a.toInt();
    std::cout << BLUE "a as int: " RESET << intResult << std::endl; 


    std::cout << std::endl;
    Fixed b(a);
    int bintResult = b.toInt();
    std::cout << BLUE "b as int: " RESET << bintResult << std::endl;
    float bfloat = b.toFloat();
    std::cout << BLUE "b as float: " RESET << bfloat << std::endl;


    std::cout << std::endl;
    Fixed c(b);
    int cintResult = c.toInt();
    std::cout << BLUE "c as int: " RESET << cintResult << std::endl;
    c.setRawBits(12345);
    int intafter = c.toInt();
    std::cout << BLUE "c as int after set: " RESET << intafter << std::endl;


    std::cout << std::endl;
    c = a;
    float cfloatResult = c.toFloat();
    std::cout << BLUE "c as float: " RESET << cfloatResult << std::endl;
    c.setRawBits(101);
    float floatafter = c.toFloat();
    std::cout << BLUE "c as float after set: " RESET << floatafter << std::endl;
    std::cout << std::endl;

    // // static casting explanation............(1)
    // float num = 3.5;
    // void *ptr = &num;

    // // we should use pointer to number
    // float *get_num = static_cast<float*>(ptr);
    // std::cout << *get_num << std::endl;

    // // static casting explanation............(2)
    // Fixed Num(2752512);
    // float get_float = Num.toFloat();
    // std::cout << "Floating point representation: " << get_float << std::endl;

}

// int main(void) 
// {
//     Fixed a;
//     Fixed const b(10);
//     Fixed const c(42.42f);
//     Fixed const d(b);
//     a = Fixed( 1234.4321f );
//     std::cout << "a is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "c is " << c << std::endl;
//     std::cout << "d is " << d << std::endl;
//     std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//     std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//     std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//     std::cout << "d is " << d.toInt() << " as integer" << std::endl;
//     return 0;
// }
