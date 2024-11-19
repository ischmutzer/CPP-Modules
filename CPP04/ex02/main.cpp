#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	AAnimal	animal;
	Cat	cat;
	Cat	copyCat = cat;
	Dog	dog;
	Dog	copyDog = dog;

	cat.getCatBrain()->setIdea("philosophing", 0);
	copyCat.getCatBrain()->setIdea("im a copy", 0);

	dog.getDogBrain()->setIdea("im a dog", 0);

	std::cout << std::endl;
	std::cout << copyCat.getCatBrain()->getIdea(0) << std::endl;
	std::cout << cat.getCatBrain()->getIdea(0) << std::endl;
	std::cout << copyDog.getDogBrain()->getIdea(0) << std::endl;

	std::cout << dog.getDogBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
}