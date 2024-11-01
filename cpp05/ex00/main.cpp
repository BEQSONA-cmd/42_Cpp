#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("b1", 10);
        std::cout << b1 << std::endl;
        b1.incrementGrade(9);
        std::cout << b1 << std::endl;
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }

    return 0;
}