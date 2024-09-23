#include "Zombie.hpp"
#include <iostream>

int	main() {
	Zombie*	zombieArray = zombieHorde(10, "camila");

	for (int i = 0; i < 10; i++) {
		zombieArray[i].announce();
		//std::cout << zombieArray[i].getName() << " has been called" <<std::endl;
		//std::cout << "\n" << i << "\n" << std::endl;
	}
	delete [] zombieArray;
	return 0;
}
