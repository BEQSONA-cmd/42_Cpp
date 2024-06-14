#include "FragTrap.hpp"

int main(void)
{
    FragTrap Emanuel("Emanuel");
    FragTrap Paulo("Paulo");
    Emanuel.attack("Paulo");
    Paulo.takeDamage(15);
    Paulo.beRepaired(15);
    Paulo.attack("Emanuel");
    Emanuel.takeDamage(15);
    Emanuel.beRepaired(15);
    Emanuel.highFivesGuys();
    Paulo.highFivesGuys();
    return(0);
}
