#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap Emanuel("Emanuel");
    ScavTrap Paulo("Paulo");
    Emanuel.attack("Paulo");
    Paulo.takeDamage(15);
    Paulo.beRepaired(15);
    Paulo.attack("Emanuel");
    Emanuel.takeDamage(15);
    Emanuel.beRepaired(15);
    Emanuel.guardGate();
    return(0);
}
