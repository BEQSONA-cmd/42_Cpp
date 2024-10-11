#ifndef BRAIN_HPP
#define BRAIN_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>

class Brain
{
    private:
    public:
        std::string ideas[100];
        
        // default constructor
        Brain();
        // copy constructor
        Brain(const Brain &brain);
        // assignment operator overload
        Brain &operator=(const Brain &brain);
        // destructor
        ~Brain();
        void new_idea(std::string idea);
};

#endif
