#include "Zombie.hpp"

int main(void)
{
    Zombie zombie = Zombie("Foo");
    zombie.announce();

    // case when its better to allocate memory on the heap
    Zombie *zombie2 = newZombie("Paulo");
    zombie2->announce();

    // case when its better to allocate memory on the stack
    randomChump("Emanuel");

    delete zombie2;
    return (0);
}
