#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& source);
		Animal&	operator=(const Animal& source);
		virtual ~Animal(); //if destructor isn't virtual, the destructors from the derived classes won't be called when stored in an Animal ptr

		std::string		getType() const;
		virtual void	makeSound() const;

	private:
	protected:
		std::string _type;
};

#endif