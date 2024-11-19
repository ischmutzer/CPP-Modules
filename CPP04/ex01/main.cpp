#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	//const Animal* cat = new Cat();
	Cat	cat;
	Cat	copyCat = cat;

	cat.getCatBrain()->setIdea("I'm a cat", 1);
	std::cout << std::endl;
	std::cout << cat.getCatBrain()->getIdea(1) << std::endl;
	std::cout << copyCat.getCatBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	Dog	dog;
	Dog	copyDog = dog;
	
	dog.getDogBrain()->setIdea("woof woof x", 10);
	std::cout << std::endl;
	dog.getDogBrain()->setIdea("woof woof woof", -1);
	std::cout << dog.getDogBrain()->getIdea(10) << std::endl;
	std::cout << copyDog.getDogBrain()->getIdea(10) << std::endl;
	std::cout << std::endl;

	Animal*	animalArray[6];
	for (int i = 0; i < 6; i++) {
		if (i < 3)
			animalArray[i] = new Dog();
		else if ( i >= 3 && i < 6)
			animalArray[i] = new Cat();
		else
		 	break ;
	}
	//delete[] animalArray; -> incorrect bc animalArray is an array of ptrs to Animal objs. delete[] is used to delete arrays that were allocated with new[]
	for (int i = 0; i < 6; i++) {
		delete animalArray[i];
	} 

	return 0;
}