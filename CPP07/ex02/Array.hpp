#pragma once

#include <cstddef>
#include <exception>
#include <string>
#include <iostream>

template <typename T>
class	Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& source);
		Array&	operator=(const Array& source);
		~Array();

		T&			operator[](size_t size);
		const T&	operator[](size_t size) const;
		size_t		size(void) const;

	private:
		T*				_array;
		unsigned int	_n;
	protected:
};


template <typename T>
void	printArray(Array<T>& arr, const std::string& id) {
	std::cout << id << " (size = " << arr.size() << ")\n";
	for (unsigned int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

#include "Array.tpp"
//NOTES

//a class template is a blueprint for a class where the data type is determined at instantiation 


//Key notes
//-> T is a placeholder for the data type
//-> the actual data type needs to be specified at instantiating the template class
//ex. Array<int>	obj;
