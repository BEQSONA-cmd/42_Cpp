#ifndef DOG_HPP
#define DOG_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
    private:
        std::string type;
    public:
        void makeSound() const;
        std::string getType() const;
        // default constructor
        Dog();
        // copy constructor
        Dog(const Dog &dog);
        // assignment operator overload
        Dog &operator=(const Dog &dog);
        // destructor
        ~Dog();
};

#endif
