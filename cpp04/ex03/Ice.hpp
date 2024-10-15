#ifndef ICE_HPP
#define ICE_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
    private:
        std::string _type;
    public:
        std::string const & getType() const;
        AMateria* clone() const;
        // default constructor
        Ice();
        // copy constructor
        Ice(const Ice &type);
        // assignment operator overload
        Ice &operator=(const Ice &type);
        // destructor
        ~Ice();
};

#endif