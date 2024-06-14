#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        // default constructor
        DiamondTrap();
        DiamondTrap(std::string name);
        // copy constructor
        DiamondTrap(const DiamondTrap &diamondtrap);
        // assignment operator overload
        DiamondTrap &operator=(const DiamondTrap &diamondtrap);
        // destructor
        ~DiamondTrap();

        void attack(const std::string &target);
        void whoAmI();

        // getters
        int getHitPoints();
        int getEnergyPoints();
        int getAttackDamage();
};

#endif
