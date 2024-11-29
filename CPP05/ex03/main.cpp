#include <iostream>
#include <exception>

int	main() {
	try {
		//a
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}