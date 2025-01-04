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
	//a
}

void	identify(Base& p) {
	//a
}
