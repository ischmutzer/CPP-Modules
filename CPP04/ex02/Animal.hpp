#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class AAnimal {
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal& source);
		AAnimal&	operator=(const AAnimal& source);
		virtual ~AAnimal();

		std::string		getType() const;
		virtual void	makeSound() const = 0;

	private:
	protected:
		std::string _type;
};

#endif

//NOTES

//-> A class with at least 1 pure virtual ft is called abstract class and cannot be instantiated.

//-> The "= 0" syntax in the virtual ft declaration makes it pure virtual

//-> A class with pure virtual fts cannot be instatiated, but it can serve as a base class.

//-> You can instatiate a class derived from it if the derived class provides implementations for all pure virtual fts.