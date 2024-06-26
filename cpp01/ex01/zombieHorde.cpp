#include "Zombie.hpp"

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zombies = new Zombie[N];
    int i = 0;
    while (i < N)
    {
        zombies[i].setName(name);
        zombies[i].announce();
        i++;
    }
    return (zombies);
}
