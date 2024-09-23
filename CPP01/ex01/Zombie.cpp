#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie() {
	_name = "";
}

Zombie::Zombie(std::string name) {
	_name = name;
}

Zombie::~Zombie() {
	std::cout << _name << " has been destroyed" << std::endl;
}

std::string	Zombie::getName() {
	return _name;
}

void	Zombie::setName(std::string name) {
	_name = name;
}

void	Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
