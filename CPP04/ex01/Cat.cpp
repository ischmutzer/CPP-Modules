#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	_catBrain = new	Brain();
}

Cat::Cat(const Cat& source) : Animal(source) {
	std::cout << "Cat copy constructor called" << std::endl;
	_catBrain = new Brain(*source._catBrain); //without dereferencing, _catBrain would point to the same Brain obj as source._catBrain
}

Cat&	Cat::operator=(const Cat& source) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &source) {
		Animal::operator=(source);
		delete _catBrain;
		_catBrain = new Brain(*source._catBrain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _catBrain; //delete frees new & delete[] frees new[]
}

void	Cat::makeSound() const {
	std::cout << "miau miau" << std::endl;
}

Brain*	Cat::getCatBrain() {
	return _catBrain;
}
