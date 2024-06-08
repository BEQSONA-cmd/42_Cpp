#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string type);
        const std::string &getType();
        void setType(std::string type);
};
#endif
