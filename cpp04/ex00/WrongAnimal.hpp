#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        void makeSound() const;
        std::string getType() const;
        // default constructor
        WrongAnimal();
        // copy constructor
        WrongAnimal(const WrongAnimal &wronganimal);
        // assignment operator overload
        WrongAnimal &operator=(const WrongAnimal &wronganimal);
        // destructor
        ~WrongAnimal();
};

#endif
