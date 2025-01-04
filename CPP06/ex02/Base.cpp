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

// void	identify(Base& p) {
// 	//a
// }
