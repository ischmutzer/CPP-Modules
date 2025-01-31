#pragma once

#include <cstddef>
#include <string>
#include <iostream>
#include <exception>

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

	protected:
	private:
		T*				_array;
		unsigned int	_n;
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
