#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
class Brain {
	public:
		Brain();
		Brain(const Brain& source);
		Brain&	operator=(const Brain& source);
		~Brain();

		void		setIdea(std::string idea, int index);
		void		printIdeas();
		std::string	getIdea(int index);

	private:
		std::string	ideas[100];
	private:
};

#endif