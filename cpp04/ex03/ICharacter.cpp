#include "ICharacter.hpp"

Character::Character(std::string name) : name(name)
{
    int i = 0;
    while(i < 4)
    {
        materia[i] = NULL;
        i++;
    }
}

Character::Character(const Character &type)
{
    this->operator=(type);
}

Character &Character::operator=(const Character &type)
{
    int i = 0;

    name = type.name;
    while(i < 4)
    {
        if (type.materia[i])
            materia[i] = type.materia[i]->clone();
        else
            materia[i] = NULL;
        i++;
    }
    return *this;
}

Character::~Character()
{
    int i = 0;
    while(i < 4)
    {
        if (materia[i])
            delete materia[i];
        i++;
    }
}

void Character::equip(AMateria* m)
{
    int i = 0;
    while(i < 4)
    {
        if (materia[i] == NULL)
        {
            materia[i] = m;
            return;
        }
        i++;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        materia[idx] = NULL;
    else
        std::cout << RED "No materia at index " << idx << RESET << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && materia[idx])
        materia[idx]->use(target);
    else
        std::cout << RED "cannot use materia at index " << idx << RESET << std::endl;
}

std::string const & Character::getName() const
{
    return name;
}
