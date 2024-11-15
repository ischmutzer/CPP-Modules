#include "ScavTrap.hpp"
#include <iostream>

int	main() {
	
	ScavTrap	a;
	ClapTrap	b("willy");

	std::cout << std::endl;
	std::cout << "INITIAL POINT AND NAME CHECK" << std::endl;
	std::cout << a.getName() << " has " << a.getHealth() << " hit points" << std::endl;
	std::cout << a.getName() << " has " << a.getEnergy() << " energy points" << std::endl;
	std::cout << a.getName() << " has " << a.getAttackDamage() << " attack damage" << std::endl;

	std::cout << std::endl;

	std::cout << b.getName() << " has " << b.getHealth() << " hit points" << std::endl;
	std::cout << b.getName() << " has " << b.getEnergy() << " energy points" << std::endl;
	std::cout << b.getName() << " has " << b.getAttackDamage() << " attack damage" << std::endl << std::endl;

	std::cout << "ATTACK CHECK" << std::endl;
	a.attack("enemy");
	std::cout << a.getName() << " has " << a.getHealth() << " hit points" << std::endl;
	std::cout << a.getName() << " has " << a.getEnergy() << " energy points" << std::endl;
	std::cout << a.getName() << " has " << a.getAttackDamage() << " attack damage" << std::endl << std::endl;

	b.attack("target");
	std::cout << b.getName() << " has " << b.getHealth() << " hit points" << std::endl;
	std::cout << b.getName() << " has " << b.getEnergy() << " energy points" << std::endl;
	std::cout << b.getName() << " has " << b.getAttackDamage() << " attack damage" << std::endl << std::endl;

	std::cout << "DAMAGE CHECK" << std::endl;
	a.takeDamage(3);
	std::cout << a.getName() << " has " << a.getHealth() << " hit points" << std::endl;
	std::cout << a.getName() << " has " << a.getEnergy() << " energy points" << std::endl;
	std::cout << a.getName() << " has " << a.getAttackDamage() << " attack damage" << std::endl << std::endl;

	b.takeDamage(7);
	std::cout << b.getName() << " has " << b.getHealth() << " hit points" << std::endl;
	std::cout << b.getName() << " has " << b.getEnergy() << " energy points" << std::endl;
	std::cout << b.getName() << " has " << b.getAttackDamage() << " attack damage" << std::endl << std::endl;

	std::cout << "HEALTH BOOST CHECK" << std::endl;
	a.beRepaired(1);
	std::cout << a.getName() << " has " << a.getHealth() << " hit points" << std::endl;
	std::cout << a.getName() << " has " << a.getEnergy() << " energy points" << std::endl;
	std::cout << a.getName() << " has " << a.getAttackDamage() << " attack damage" << std::endl << std::endl;

	b.beRepaired(1);
	std::cout << b.getName() << " has " << b.getHealth() << " hit points" << std::endl;
	std::cout << b.getName() << " has " << b.getEnergy() << " energy points" << std::endl;
	std::cout << b.getName() << " has " << b.getAttackDamage() << " attack damage" << std::endl << std::endl;
}