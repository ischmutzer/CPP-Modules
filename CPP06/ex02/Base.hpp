#pragma once

#include <iostream>
#include <cstdlib>

class Base {
	public:
		virtual ~Base();

	protected:
	private:
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

//NOTES

//virtual public destructor
//-> ensures proper destructor is called for derived classes when it is
//deleted through a ptr to the base class