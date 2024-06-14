#include "DiamondTrap.hpp"

int main()
{
    std::cout << YELLOW << "Testing ClapTrap" << RESET << std::endl;
    ClapTrap Beqa("Beqa");
    Beqa.attack("Paulo");
    Beqa.takeDamage(10);
    Beqa.beRepaired(5);
    std::cout << std::endl;

    std::cout << YELLOW << "Testing ScavTrap" << RESET << std::endl;
    ScavTrap Paulo("Paulo");
    Paulo.attack("Emanuel");
    Paulo.guardGate();
    Paulo.takeDamage(15);
    Paulo.beRepaired(15);
    std::cout << std::endl;

    std::cout << YELLOW << "Testing FragTrap" << RESET << std::endl;
    FragTrap Tobias("Tobias");
    Tobias.attack("Paulo");
    Tobias.takeDamage(15);
    Tobias.beRepaired(15);
    Tobias.highFivesGuys();
    std::cout << std::endl;

    std::cout << YELLOW << "Testing DiamondTrap" << RESET << std::endl;
    DiamondTrap Emanuel("Emanuel");
    std::cout << GREEN << "Fragtrap hit points: " << BLUE << "100" << RESET << std::endl;
    std::cout << GREEN << "Scavtrap energy points: " << BLUE << "50" << RESET << std::endl;
    std::cout << GREEN << "Fragtrap attack damage: " << BLUE << "30" << RESET << std::endl;
    std::cout << GREEN << "Emanuel's hit points: " << BLUE << Emanuel.getHitPoints() << RESET << std::endl;
    std::cout << GREEN << "Emanuel's energy points: " << BLUE << Emanuel.getEnergyPoints() << RESET << std::endl;
    std::cout << GREEN << "Emanuel's attack damage: " << BLUE << Emanuel.getAttackDamage() << RESET << std::endl;
    Emanuel.attack("Paulo");
    Emanuel.takeDamage(15);
    Emanuel.beRepaired(15);
    Emanuel.whoAmI();
    Emanuel.guardGate();
    Emanuel.highFivesGuys();
    Emanuel.attack("Tobias");

    std::cout << std::endl;

	return (0);
}