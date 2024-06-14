#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
	public:
		// default constructor
		ScavTrap();
		ScavTrap(std::string name);
		// copy constructor
		ScavTrap(const ScavTrap &scavtrap);
		// assignment operator overload
		ScavTrap &operator=(const ScavTrap &scavtrap);
		// destructor
		~ScavTrap();

		void attack(const std::string &target);
		void guardGate();
};

#endif
