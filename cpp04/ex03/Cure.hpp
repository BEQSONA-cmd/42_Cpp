#ifndef CURE_HPP
#define CURE_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        AMateria* clone() const;
        // default constructor
        Cure();
        // copy constructor
        Cure(const Cure &type);
        // assignment operator overload
        Cure &operator=(const Cure &type);
        // destructor
        ~Cure();
};

#endif