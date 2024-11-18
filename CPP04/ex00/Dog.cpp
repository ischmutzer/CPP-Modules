#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

/* Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog default constructor called" << std::endl;
} */

Dog::Dog(const Dog& source) : Animal(source) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& source){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &source)
		Animal::operator=(source);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "woof woof" << std::endl;
}
