#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class	Zombie {
	private:
		std::string	_name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		std::string	getName();
		void		setName(std::string name);
		void		announce();
};

Zombie* zombieHorde( int N, std::string name );

#endif