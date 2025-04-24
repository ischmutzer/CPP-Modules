#include "Span.hpp"
#include <climits>
#include <stdexcept>

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {
	_container.reserve(_n);
}

Span::Span(const Span& source) : _container(source._container), _n(source._n) {}

Span& Span::operator=(const Span& source) {
    if (this != &source) {
        _n = source._n;
        _container = source._container;
    }
    return *this;
}

Span::~Span() {}

void    Span::addNumber(unsigned int n) {
	if (_container.size() >= _n) {
		std::ostringstream	str;
		str << "Error: Cannot add number '" << n << "'. Span is full.";
		throw std::out_of_range(str.str());
	}
	_container.push_back(n);
}

void	Span::addNumber(const std::vector<int>& numbers) {
	if (_container.size() + numbers.size() > _container.capacity())
		throw std::out_of_range("Error: Cannot add elements. Span would exceed its capacity.");
	_container.insert(_container.end(), numbers.begin(), numbers.end());
}

int	Span::shortestSpan() const {
	if (_container.size() < 2)
		throw	std::logic_error("Error: Not enough elements to calculate a span.");
	
	std::vector<int>	sorted = _container;
	std::sort(sorted.begin(), sorted.end());
	long long	minDiff = static_cast<long long>(sorted[1]) - static_cast<long long>(sorted[0]);
	for (size_t i = 1; i < sorted.size(); i++) {
		long long	diff = static_cast<long long>(sorted[i]) - static_cast<long long>(sorted[i - 1]);
		if (diff < minDiff)
			minDiff = diff;
	}
	return static_cast<int>(minDiff);
}

long long	Span::longestSpan() const {
	if (_container.size() < 2)
		throw std::logic_error("Error: Insufficient elements to calculate a span.");
	long long	min = *std::min_element(_container.begin(), _container.end());
	long long	max = *std::max_element(_container.begin(), _container.end());
	
	return (max - min);
}


//NOTES

//std::vector handles deep copying by default
//.reserve allocates memory for the specified amount of elements
//but it does not initialize them.

//In C++, if you don’t explicitly initialize a member in the member
//initializer list, it will be default-initialized.
//default constructor of std::vector creates an empty vector

//std::logic_error should be used when the error is due to a logical flaw
//and you want to enforce preconditions

//use adjacent difference loop to calculate the min value

//std::min/max_element() returns an iterator to the smallest/biggest
//element in the range.
//an iterator is an object that points to an element in a container
//therefore you need to dereference the iterator to access the value


//reserve(_n) -> is a performance optimization technique
//without reserve, the vector would need to realloc and copz its elements as ir grows.

//std::min_element and std::max_element return iterators, therefore we
//dereference it to access the value it points to.