#include "Harl.hpp"
#include <iostream>

Harl::Harl() {

}

Harl::~Harl() {
}

void	Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	
	typedef void	(Harl::*pointerToFunctions)();
	pointerToFunctions	functionPointers[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functionPointers[i])();
			return ;
		}
	}
	std::cout << "Error: invalid level" << std::endl;
}
