#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(): _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = source;
}

ClapTrap::ClapTrap(std::string name): _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap parameterized constructor called" << std::endl;
	_name = name;
}


ClapTrap::ClapTrap(std::string name, unsigned int health, unsigned int energy, unsigned int damage): _name(name), _hitPoints(health), _energyPoints(energy), _attackDamage(damage) {
	std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& source) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;

	if (this != &source) {
		_name			= source._name;
		_hitPoints		= source._hitPoints;
		_energyPoints	= source._energyPoints;
		_attackDamage	= source._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << " ClapTrap destructor called" << std::endl;
}

std::string	ClapTrap::getName() {
	if (_name.empty())
		return "ClapTrap";
	return _name;
}

int	ClapTrap::getHealth() {
	return _hitPoints;
}

int	ClapTrap::getEnergy() {
	return _energyPoints;
}

int	ClapTrap::getAttackDamage() {
	return _attackDamage;
}

void	ClapTrap::setHealth(unsigned int amount) {
	_hitPoints = amount;
}

void	ClapTrap::setEnergy(unsigned int amount) {
	_energyPoints = amount;
}

//causes target to lose <attack damage> hit points 
//attack costs 1 energy point
void	ClapTrap::attack(const std::string& target) {
	if (this->getHealth() == 0 || this->getEnergy() == 0) {
		if (this->getHealth() == 0)
			std::cout << "ClapTrap " << this->getName() << " has no hit/health points left" << std::endl;
		else
			std::cout << "ClapTrap " << this->getName() << " has no energy points left" << std::endl;
		return ;
	}
	else {
		this->setEnergy((this->getEnergy() - 1));
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHealth() == 0) {
		std::cout << "ClapTrap " << this->getName() << " has no hit/health points left" << std::endl;
		return ;
	}
	else {
		std::cout << "ClapTrap " << this->getName() << " suffered " << amount << " points of damage!" << std::endl;
		this->setHealth((this->getHealth() - amount));
	}
}

//if no hit points (health) left, ClapTrap is dead
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->getHealth() == 0 || this->getEnergy() == 0) {
		if (this->getHealth() == 0)
			std::cout << "ClapTrap " << this->getName() << "has no hit/health points left" << std::endl;
		else
			std::cout << "ClapTrap " << this->getName() << "has no energy points left" << std::endl;
		return ;
	}
	else {
		this->setHealth((this->getHealth() + amount));
		this->setEnergy((this->getEnergy() - 1));
		std::cout << "ClapTrap " << this->getName() << " regained " << amount << " hit/health points" << std::endl;
	}
}
