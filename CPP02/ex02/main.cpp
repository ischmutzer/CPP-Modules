#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

/* int main() {
    Fixed a(10);
    Fixed b(5);
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    if (a > b)
        std::cout << "a is bigger -> true" << std::endl;
    else
     std::cout << "a is bigger -> false" << std::endl;

    if (a == b)
        std::cout << "values are equal" << std::endl;
    if (a != b)
        std::cout << "values are unequal" << std::endl;
    std::cout << a.max(a, b) << std::endl;
    std::cout << a.min(a, b) << std::endl;

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;
} */