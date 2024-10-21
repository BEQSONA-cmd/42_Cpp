#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
    public:
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
        virtual std::string const & getName() const = 0;
        virtual ~ICharacter() {}    
};

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* materia[4];
    public:
        Character(std::string name);
        Character(const Character &type);
        Character &operator=(const Character &type);
        ~Character();

        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        std::string const & getName() const;
};

#endif
