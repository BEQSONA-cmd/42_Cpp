#include "Template.hpp"

// int main( void ) 
// {
//     int a = 2;
//     int b = 3;
//     ::swap( a, b );
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//     std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//     std::string c = "chaine1";
//     std::string d = "chaine2";
//     ::swap(c, d);
//     std::cout << "c = " << c << ", d = " << d << std::endl;
//     std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//     std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
//     return 0;
// }

int main()
{
    int a = 2;
    int b = 3;
    std::cout << YELLOW << "a = " << a << ", b = " << b << RESET << std::endl;
    swap(a, b);
    std::cout << GREEN << "a = " << a << ", b = " << b << RESET << std::endl;
    std::cout << BLUE << "min(a, b) = " << min(a, b) << RESET << std::endl;
    std::cout << CYAN << "max(a, b) = " << max(a, b) << RESET << std::endl;
    return 0;
}