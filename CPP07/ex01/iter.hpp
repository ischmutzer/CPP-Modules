#pragma once

#include <cstddef>
#include <iostream>

template <typename T, typename func>
void iter(T* arrayAddress, size_t arrayLength, func function) {
	for (size_t i = 0; i < arrayLength; i++) {
		function(arrayAddress[i]);
	}
	std::cout << "\n";
}



//NOTES

//instead of <typename T1, typename T2, typename T3>
//<typename T, typename func> T is so that arrayAddress can be a ptr
//to any type of memory address, int*, double*, class*, etc
//The template parameter Func allows the compiler to deduce the
//correct type for whatever kind of callable object is passed
