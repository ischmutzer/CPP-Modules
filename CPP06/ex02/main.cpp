#include "Base.hpp"
#include "ABC.hpp"
#include <ctime>

int	main() {
	std::srand(std::time(0)); //seeding random number generator
	for (int i = 0; i < 5; i++) {
        Base* ptr = generate();
        
        std::cout << "Test " << i + 1 << ":\n";
        std::cout << "Pointer identification: ";
        identify(ptr);

		std::cout << "Reference identification: ";
        identify(*ptr);

		std::cout << "-------------------" << std::endl;
        
        delete ptr;
	}
	// Base* a = new B();
	// identify(*a);
};
