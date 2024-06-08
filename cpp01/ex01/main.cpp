#include "Zombie.hpp"

int main(void)
{
    std::cout << YELLOW "[check if the Zombie class is working]" << RESET << std::endl;
    Zombie zombie = Zombie("Foo");
    zombie.announce();
    
    std::cout << YELLOW "[check if the zombieHorde function is working]" << RESET << std::endl;
    Zombie *zombies = zombieHorde(5, "Emanuel");

    std::cout << YELLOW "[delete the zombies]" << RESET << std::endl;
    delete [] zombies;
    return (0);
}
