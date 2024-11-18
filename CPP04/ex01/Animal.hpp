#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& source);
		Animal&	operator=(const Animal& source);
		virtual ~Animal();

		std::string		getType() const;
		virtual void	makeSound() const;

	private:
	protected:
		std::string _type;
};

#endif