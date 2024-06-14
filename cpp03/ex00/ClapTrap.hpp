#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int hit_points;
        int energy_points;
        int attak_damage;
    public:
        // default constructor
        ClapTrap();
        ClapTrap(std::string n_name);
        // copy constructor
        ClapTrap(const ClapTrap &claptrap);
        // assignment operator overload
        ClapTrap &operator=(const ClapTrap &claptrap);
        // destructor
        ~ClapTrap();

        void attak(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
