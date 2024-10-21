#include "IMateriaSource.hpp"

MateriaSource::MateriaSource()
{
    int i = 0;
    while(i < 4)
    {
        materia[i] = NULL;
        i++;
    }
}

MateriaSource::MateriaSource(const MateriaSource &type) : IMateriaSource()
{
    this->operator=(type);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &type)
{
    int i = 0;
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

MateriaSource::~MateriaSource()
{
    int i = 0;
    while(i < 4)
    {
        if (materia[i])
            delete materia[i];
        i++;
    }
}

void MateriaSource::learnMateria(AMateria* m)
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

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    while(i < 4)
    {
        if (materia[i] && materia[i]->getType() == type)
            return materia[i]->clone();
        i++;
    }
    if(i == 4)
        std::cout << RED "Materia not found" RESET << std::endl;
    return NULL;
}

