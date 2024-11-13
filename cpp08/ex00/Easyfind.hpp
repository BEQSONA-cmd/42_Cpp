#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>

class Easyfind
{
    private:
    public:
        Easyfind();
        Easyfind(const Easyfind &easyfind);
        Easyfind &operator=(const Easyfind &easyfind);
        ~Easyfind();
};

#endif
