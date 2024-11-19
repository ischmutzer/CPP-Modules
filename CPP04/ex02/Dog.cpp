#include "Dog.hpp"
#include <iostream>

Dog::Dog() : AAnimal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
	_dogBrain = new Brain();
}


Dog::Dog(const Dog& source) : AAnimal(source) {
	std::cout << "Dog copy constructor called" << std::endl;
	_dogBrain = new Brain(*source._dogBrain);
}

Dog&	Dog::operator=(const Dog& source){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &source) {
		AAnimal::operator=(source);
		delete _dogBrain;
		_dogBrain = new Brain(*source._dogBrain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _dogBrain;
}

void	Dog::makeSound() const {
	std::cout << "woof woof" << std::endl;
}

Brain*	Dog::getDogBrain() {
	return _dogBrain;
}
