#include "Serializer.hpp"
#include <stdint.h>

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& source) {
	*this = source;
}

Serializer& Serializer::operator=(const Serializer& source) {
	if (this != &source) {
		//copy elements
	}
	return *this;
}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data* ptr) {
	uintptr_t	value = reinterpret_cast<uintptr_t>(ptr);
	return value;
}

// reinterpret_cast is used to convert a pointer of some data type into a pointer
//of another data type, even if the data types before and after conversion are different.

Data*	Serializer::deserialize(uintptr_t raw) {
	Data*	ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}


//NOTES

//reinterpret wont fail but can cause undefined behaviour if used incorrectly
//cant use static_cast or dynamic_cast ( for polymorphism) bc theyre both type safe 