#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <sstream>

template <typename T>
typename T::const_iterator	easyfind(const T& container, int x) {
	typename T::const_iterator index;
	index = std::find(container.begin(), container.end(), x);
	if (index != container.end()) {
		return index;
	}
	else {
		std::ostringstream str;
		str << "FAILURE: Couldn't find an occurrence of " << x;
	 	throw std::out_of_range(str.str());
	}
}

#endif



//NOTES

//template keyword -> defines that the given entity is a template
//template ft syntax: template < parameter-list > function-declaration

//typename keyword -> defines template parameters (can be replaced bz keyword <class>)
