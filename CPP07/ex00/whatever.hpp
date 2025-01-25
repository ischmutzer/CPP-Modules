#pragma once

#include <iostream>

/* template <typename T>
bool	checkDataType(T, T) {
	return true;
}

template <typename T1, typename T2>
bool	checkDataType(T1, T2) {
	return false;
} */

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(T a, T b) {
	return (a < b) ? a : b;
}

template <typename T>
T	max(T a, T b) {
	return (a > b) ? a : b; //if a is bigger than b return a, otherwise b
}

//NOTES

//template fts -> provide generic programming capabilities
//allows you to write fts and classses that work with any data type

