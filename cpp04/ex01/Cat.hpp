#ifndef CAT_HPP
#define CAT_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
    private:
        std::string type;
        Brain   *brain;
    public:
        void makeSound() const;
        std::string getType() const;

        Brain *get_brain();
        // default constructor
        Cat();
        // copy constructor
        Cat(const Cat &cat);
        // assignment operator overload
        Cat &operator=(const Cat &cat);
        // destructor
        ~Cat();
};

#endif
