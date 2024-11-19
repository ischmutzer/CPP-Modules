#include "Animal.hpp"
#include <iostream>
#include <string>

AAnimal::AAnimal() {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "AAnimal parameterized constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& source) : _type(source._type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& source) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &source)
		_type = source._type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string	AAnimal::getType() const {
	return _type;
}

void	AAnimal::makeSound() const {
	std::cout << "**AAnimal sound**" << std::endl;
}


//NOTES

//runtime polymorphism -> compiler resolves the object at run time and then it
//decides which ft call should be associated with that object

//Virtual Member Functions in C++
//-> a ft that is declared within a base class and is meant to be overridden in
//derived classes. It enables the program to dynamically determine the appropriate
//ft to call based on the type of object being pointed to, rather than the type of
//the pointer or reference.