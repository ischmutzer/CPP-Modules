#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain() {
	std::cout << "Brain default constructor" << std::endl;
	for (int i = 0; i < 100; i++) {
		std::stringstream ideaNum;
		ideaNum << i;
		ideas[i] = "Default idea n°" + ideaNum.str();
	}
}

Brain::Brain(const Brain& source) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = source.ideas[i];
	}
}

Brain&	Brain::operator=(const Brain& source) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &source) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = source.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(std::string idea, int index) {
	if (index > 99 || index < 0) {
		std::cout << "Index out of range" << std::endl;
		return ;
	}
	else if (idea.empty())
		ideas[index] = "empty idea";
	else
		ideas[index] = idea;
}

void	Brain::printIdeas() {
	for (int i = 0; i < 100; i++) {
		std::cout << ideas[i] << std::endl;
	}
}

std::string	Brain::getIdea(int index) {
	if (index > 99 || index < 0) {
		std::cerr << "index out of range" << std::endl;
	}
	return ideas[index];
}
