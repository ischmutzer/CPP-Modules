#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>

class   HumanB {
	private:
		std::string     _name;
		std::string*    _weapon;
	public:
		HumanB();
		~HumanB();

		//void    attack();
};

#endif