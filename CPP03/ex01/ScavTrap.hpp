#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& source);
		ScavTrap&	operator=(const ScavTrap& source);
		~ScavTrap();
/* 
		std::string	getName();
		int			getHealth();
		int			getEnergy();
		int			getAttackDamage(); */

		void	guardGate();

	private:
};

#endif