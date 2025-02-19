#include "whatever.hpp"
#include <iostream>

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

	std::cout << "\nMax(2, 8): " << max(a, b) << std::endl;
	std::cout << "Min(2, 8): " << min(a, b) << std::endl;

	std::cout << "\nMax(2.2, 8.8): " << max(c, d) << std::endl;
	std::cout << "Min(2.2, 8.8): " << min(c, d) << "\n\n";
	
	// std::cout << "Mismatched data types: " << std::endl;
	// swap(a, c);

	// Edge case: Swapping same values
	int e = 5, f = 5;
	std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
	swap(e, f);
	std::cout << "After swap: e = " << e << ", f = " << f << "\n\n"; // should remain same

	// Edge case: min/max with negative numbers
	std::cout << "Min(-10, -20): " << min(-10, -20) << std::endl;
	std::cout << "Max(-10, -20): " << max(-10, -20) << "\n\n";

	// Edge case: Large numbers
	std::cout << "Min(999999999, -999999999): " << min(999999999, -999999999) << std::endl;
	std::cout << "Max(999999999, -999999999): " << max(999999999, -999999999) << std::endl;

	return 0;
}

//subject main
/* int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
} */
