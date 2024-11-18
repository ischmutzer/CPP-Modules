#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		//Dog(std::string type);
		Dog(const Dog& source);
		Dog&	operator=(const Dog& source);
		~Dog();

		void	makeSound() const;

	private:
	protected:
};

#endif