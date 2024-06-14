#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
    public:
        // default constructor
        FragTrap();
        FragTrap(std::string name);
        // copy constructor
        FragTrap(const FragTrap &fragtrap);
        // assignment operator overload
        FragTrap &operator=(const FragTrap &fragtrap);
        // destructor
        ~FragTrap();

        void highFivesGuys(void);
};

#endif
