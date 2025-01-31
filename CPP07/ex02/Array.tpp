#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n) {
	_array = new T[_n];
}

template <typename T>
Array<T>::Array(const Array& source) : _n(source._n) {
	_array = new T[_n];
	for (unsigned int i = 0; i < _n; i++) {
		_array[i] = source._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& source) {
	if (this != &source) {
		if (_array)
			delete [] _array;
		_n = source._n;
		_array = new T[_n];
		for (unsigned int i = 0; i < _n; i++) {
			_array[i] = source._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete []	_array;
}

template <typename T>
T&	Array<T>::operator[](size_t size) {
	if (size < 0 || size >= _n)
		throw std::out_of_range("EROOR: Index out of range");
	return _array[size];
}

template <typename T>
const T&	Array<T>::operator[](size_t size) const {
	if (size < 0 || size >= _n)
		throw std::out_of_range("EROOR: Index out of range");
	return	_array[size];
}

template <typename T>
size_t	Array<T>::size() const {
	return _n;
}
