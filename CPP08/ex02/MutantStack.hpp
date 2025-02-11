#pragma once

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack(const MutantStack& source) : std::stack<T>(source) {};
		MutantStack&	operator=(const MutantStack& source) {
			if (this != &source) {
				std::stack<T>::operator=(source);
			}
			return *this;
		};
		~MutantStack() {};

		typedef typename std::deque<T>::iterator	iterator;
		iterator	begin()	{ return this->c.begin();}
		iterator	end()	{ return this->c.end();}

	protected:
	private:
};

//NOTES

//->std::stack is an adapter not a container. It doesn't directly store its elements
//but instead wraps around another container. This underlying container is where the
//actual elements are stored.
//*In std::stack the underlying container is typically accessed as "c"
//std::stack<T> inherits from the container class (the container is publicly accessible)
//"c" is part of the std::stack<T> internal implementation. 
//*std::deque is its default container class
