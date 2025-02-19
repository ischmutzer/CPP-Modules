#pragma once

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T&	min(const T& a, const T& b) {
	return (a < b) ? a : b;
}

template <typename T>
const T&	max(const T& a, const T& b) {
	return (a > b) ? a : b; //if a is bigger than b return a, otherwise b
}

//NOTES

//template fts -> provide generic programming capabilities
//allows you to write fts and classses that work with any data type

