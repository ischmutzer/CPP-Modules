#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("Base", 100, 50, 20) {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

//ScavTrap is derived from ClapTrap therefore it can be treated as an instance of the base class.
//bc the derived class contains all memebers of the base class, plus additional members it defines
//ClapTrap(source) calls the copy constructor of the base class
ScavTrap::ScavTrap(const ScavTrap& source) : ClapTrap(source) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& source) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &source) {
		ClapTrap::operator=(source);
	}
	return *this;
}

void	guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}