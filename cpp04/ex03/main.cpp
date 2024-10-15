#include "AMateria.hpp"
#include "Ice.hpp"
#include "cure.hpp"

int main(void)
{
    // AMateria materia;

    Ice *ice = new Ice();
    Cure *cure = new Cure();

    std::cout << GREEN "Ice type: " BLUE << ice->getType() << RESET << std::endl;
    std::cout << GREEN "Cure type: " BLUE << cure->getType() << RESET << std::endl;

    delete ice;
    delete cure;
}