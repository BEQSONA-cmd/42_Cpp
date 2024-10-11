#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    private:
    public:
        void makeSound() const;
        std::string getType() const;
        // default constructor
        WrongCat();
        // copy constructor
        WrongCat(const WrongCat &wrongcat);
        // assignment operator overload
        WrongCat &operator=(const WrongCat &wrongcat);
        // destructor
        ~WrongCat();
};

#endif
