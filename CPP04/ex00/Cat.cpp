#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

/* Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat default constructor called" << std::endl;
} */

/* Cat::Cat(const Cat& source) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& source) {
	std::cout << "Cat copy assignment operator called" << std::endl;
} */

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "miau miau" << std::endl;
}
