#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		//Cat(std::string type);
		Cat(const Cat& source);
		Cat&	operator=(const Cat& source);
		~Cat();

		void	makeSound() const;

	private:
	protected:
};

#endif