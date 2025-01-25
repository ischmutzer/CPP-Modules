#include "whatever.hpp"

int	main() {
	int a = 2, b = 8;
	double c = 2.2, d = 8.8;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "Int swap: ";
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "\nc = " << c << ", d = " << d << std::endl;
	std::cout << "Double swap: ";
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;

	std::cout << "\nMax of a and b: " << max(a, b) << std::endl;
	std::cout << "Min of a and b: " << min(a, b) << std::endl;

	std::cout << "\nMax of c and d: " << max(c, d) << std::endl;
	std::cout << "Min of c and d: " << min(c, d) << std::endl;
	
	// std::cout << "Mismatched data types: " << std::endl;
	// swap(a, c);

	return 0;
}
