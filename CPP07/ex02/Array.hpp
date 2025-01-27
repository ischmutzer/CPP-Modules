#pragma once

template <typename T>
class	Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& source);
		Array&	operator=(const Array& source);
		~Array();
	private:
	protected:
};

//NOTES

//a class template is a blueprint for creating classes that depend on one or
//more types.

//Key notes
//-> T is a placeholder for the data type
//-> the actual data type needs to be specified at instantiating the template class
//ex. Array<int>	obj;
