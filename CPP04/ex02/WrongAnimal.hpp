#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& source);
		WrongAnimal&	operator=(const WrongAnimal& source);
		~WrongAnimal();

		void	makeSound();
		
	private:
	protected:
		std::string _type;
};

#endif