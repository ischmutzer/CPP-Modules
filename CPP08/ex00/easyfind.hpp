#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <sstream>

template <typename T>
typename T::const_iterator	easyFind(const T& container, int x) {
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


//T::const_iterator is an iterator with read-only permissions, user can only
//read but not modify elements of the container (unless they somehow typecast the const away)
//T::const_iterator is a dependent name therefore you need the typename keyword until T gets replaced by an actual data type

//std::find() searches for x from the given iterators. If it finds x, it'll return an it
//to the element, otherise it'll return an it pointing to container.end()

//std::ostringstream creates a string stream (from <sstream>) and we can write into it with the << operator, like std::cout
