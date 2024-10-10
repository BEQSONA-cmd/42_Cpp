#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
    public:
        virtual void makeSound() const;
        std::string virtual getType() const;
        // default constructor
        Animal();
        // copy constructor
        Animal(const Animal &animal);
        // assignment operator overload
        Animal &operator=(const Animal &animal);
        // destructor
        virtual ~Animal();
};

#endif
