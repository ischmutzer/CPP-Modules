#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& source);
		Dog&	operator=(const Dog& source);
		~Dog();

		void	makeSound() const;
		Brain*	getDogBrain();

	private:
		Brain*	_dogBrain;

	protected:
};

#endif