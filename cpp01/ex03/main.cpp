#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	std::cout << YELLOW << "AWP constructor called" << RESET << std::endl;
	Weapon AWP = Weapon("AWP");
	std::cout << YELLOW << "Glock constructor called" << RESET << std::endl;
	Weapon glock = Weapon("Glock");
	std::cout << YELLOW << "AK47 constructor called" << RESET << std::endl;
	Weapon AK47 = Weapon("AK47");
	std::cout << YELLOW << "M4A1 constructor called\n" << RESET << std::endl;
	Weapon M4A1 = Weapon("M4A1");

	std::cout << YELLOW << "Paulo and Emanuel join the game...\n" << RESET << std::endl;
	HumanA Paulo = HumanA("Paulo", AK47);
	HumanB Emanuel = HumanB("Emanuel");

	Paulo.attack();
	std::cout << YELLOW << "RATATATATATATAAA...\n" << RESET << std::endl;

	Emanuel.attack();
	Emanuel.setWeapon(M4A1);
	Emanuel.attack();
	std::cout << YELLOW << "PEW PEW PEW PEW PEW...\n" << RESET << std::endl;

	Emanuel.setWeapon(AWP);
	Emanuel.attack();
	std::cout << YELLOW << "KABOOM KABOOM KABOOM...\n" << RESET << std::endl;

	Emanuel.setWeapon(glock);
	Emanuel.attack();
	std::cout << YELLOW << "POP POP POP POP POP...\n" << RESET << std::endl;

	return (0);
}

// int	main(void)
// {
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanA bob("Bob", club);
// 		bob.attack();
// 		club.setType("some other type of club");
// 		bob.attack();
// 	}
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanB jim("Jim");
// 		jim.setWeapon(club);
// 		jim.attack();
// 		club.setType("some other type of club");
// 		jim.attack();
// 	}
// 	return (0);
// }