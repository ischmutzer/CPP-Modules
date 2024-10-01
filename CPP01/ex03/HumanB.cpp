#include "HumanB.hpp"
#include <string>
#include <iostream>

HumanB::HumanB() {
	_name = "";
	_weapon = NULL;
}

HumanB::HumanB(std::string name) {
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB() {

}

void    HumanB::attack() {
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() <<  std::endl;
	else
		std::cout << _name << " has no weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon* weapon) {
	_weapon = weapon;
}
