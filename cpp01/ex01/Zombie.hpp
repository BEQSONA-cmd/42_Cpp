#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

class Zombie
{
    private:
        std::string name;
    public:
        void announce(void);
        void setName(std::string name);
        Zombie(std::string name);
        Zombie();
        ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif