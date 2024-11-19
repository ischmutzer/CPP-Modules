#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	public:
		Cat();
		Cat(const Cat& source);
		Cat&	operator=(const Cat& source);
		~Cat();

		void	makeSound() const;
		Brain*	getCatBrain();

	private:
		Brain*	_catBrain;

	protected:
};

#endif