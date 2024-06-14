#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Emanuel("Emanuel");
    Emanuel.attak("Paulo");
    Emanuel.attak("Paulo");
    Emanuel.beRepaired(4);
    Emanuel.attak("Paulo");
    Emanuel.attak("Paulo");
    Emanuel.takeDamage(5);
    return(0);
}
