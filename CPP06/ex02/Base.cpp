#include "Base.hpp"
#include "ABC.hpp"

Base::~Base() {
	std::cout << "Base destructor called" << std::endl;
}

Base*	generate(void) {
	int	randomValue = rand() % 3;
	switch (randomValue) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base* p) {
	A*	derivedA = dynamic_cast<A*>(p);
	if (derivedA)
		std::cout << "Base* type A class" << std::endl;
	B*	derivedB = dynamic_cast<B*>(p);
	if (derivedB)
		std::cout << "Base* type B class" << std::endl;
	C*	derivedC = dynamic_cast<C*>(p);
	if (derivedC)
		std::cout << "Base* type C class" << std::endl;
}

//SYNTAX
//-> dynamic_cast<target-type>(expression)
//<target-type> is the type you want to cast the obj to  
//(expression) is the obj, ptr or ref youz want to cast

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Base ref is type A class" << std::endl;
		return ;
	} catch (std::exception& e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Base ref is type B class" << std::endl;
		return ;
	} catch (std::exception& e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Base ref is type C class" << std::endl;
		return ;
	} catch (std::exception& e) {}
}

// The function uses a series of try-catch blocks to attempt the dynamic_cast for each
//derived type (A, B, and C).
// If the cast succeeds, the corresponding type is printed, and the function returns
//immediately.
// If the cast fails, the std::bad_cast exception is caught, and the function moves on
//to the next try-catch block.


//NOTES

//<target_type> an (expression) must involve classes in the same
//inheritance hierarchy.
//RTTI Dependency -> meaning dynamic_cast uses runtime type info to determine if (expression) can be safely cast to <target_type> 
//the base class must include at least one virtual ft
//ptrs return NULL if failure
//refs throw an exception