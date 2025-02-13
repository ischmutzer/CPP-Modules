#include "Base.hpp"
#include "ABC.hpp"
#include <ctime>

int main() {
    std::srand(std::time(0)); // Seed random number generator

    // Test Cases 1-5: Randomly generated objects
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

    // Test Case 6: Explicitly create an A object
    Base* a = new A();
    std::cout << "Test 6:\n";
    std::cout << "Pointer identification: ";
    identify(a);
    std::cout << "Reference identification: ";
    identify(*a);
    std::cout << "-------------------" << std::endl;
    delete a;

    // Test Case 7: Explicitly create a B object
    Base* b = new B();
    std::cout << "Test 7:\n";
    std::cout << "Pointer identification: ";
    identify(b);
    std::cout << "Reference identification: ";
    identify(*b);
    std::cout << "-------------------" << std::endl;
    delete b;

    // Test Case 8: Explicitly create a C object
    Base* c = new C();
    std::cout << "Test 8:\n";
    std::cout << "Pointer identification: ";
    identify(c);
    std::cout << "Reference identification: ";
    identify(*c);
    std::cout << "-------------------" << std::endl;
    delete c;

    // Test Case 9: Test with a null pointer
    Base* nullPtr = NULL;
    std::cout << "Test 9:\n";
    std::cout << "Pointer identification: ";
    identify(nullPtr); // Should handle null pointer gracefully
    std::cout << "-------------------" << std::endl;

    // Test Case 10: Test with a Base pointer to a B object
    Base* basePtr = new B();
    std::cout << "Test 10:\n";
    std::cout << "Pointer identification: ";
    identify(basePtr);
    std::cout << "Reference identification: ";
    identify(*basePtr);
    std::cout << "-------------------" << std::endl;
    delete basePtr;

    return 0;
}

/* int	main() {
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
}; */
