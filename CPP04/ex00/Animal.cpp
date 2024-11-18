#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal parameterized constructor called" << std::endl;
}

/* Animal::Animal(const Animal& source) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& source) {
	std::cout << "Animal copy assignment operator called" << std::endl;
} */

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType() const {
	return _type;
}

void	Animal::makeSound() const {
	std::cout << "**Animal sound**" << std::endl;
}


//NOTES

//runtime polymorphism -> compiler resolves the object at run time and then it
//decides which ft call should be associated with that object

//Virtual Member Functions in C++
//-> a ft that is declared within a base class and is meant to be overridden in
//derived classes. It enables the program to dynamically determine the appropriate
//ft to call based on the type of object being pointed to, rather than the type of
//the pointer or reference.