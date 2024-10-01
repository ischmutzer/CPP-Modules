#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

//ref members must be initialized in the member initializer list because references must be bound to an existing object (cannot be uninitialized)
//at the time of their creation.
//They cannot be reassigned or left uninitialized! -> whichb is also why human a uses a reference since it will always hold a weapon

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {

}

void    HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}