#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	WrongAnimal		a;
	WrongAnimal*	c = new WrongAnimal();
	WrongCat		b;
	WrongAnimal*	d = new WrongCat();

	std::cout << std::endl;
	a.makeSound();
	b.makeSound();
	c->makeSound();
	d->makeSound(); //calling makeSound() on a WrongCat obj through a WrongAnimal ptr will call the WrongAnimal version of makeSound().
	std::cout << std::endl;

	return 0;
}