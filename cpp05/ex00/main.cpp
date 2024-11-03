#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat emanuel("emanuel", 10);
        std::cout << emanuel << std::endl;
        emanuel.incrementGrade(9);
        std::cout << emanuel << std::endl;
    }
    catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }

    return 0;
}