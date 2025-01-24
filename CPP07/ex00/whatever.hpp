#pragma once

template <typename T>
T swap(T a, T b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(T a, T b) {
	if (a == b || a > b)
		return b;
	if (a < b)
		return a;
}

template <typename T>
T	max(T a, T b) {
	if (a == b || b > a)
		return b;
	else
		return a;
}

//NOTES

//template fts -> provide generic programming capabilities
//allows you to write fts and classses that work with any data type

