#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <algorithm>

class Span {
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& source);
        Span& operator=(const Span& source);
        ~Span();

        void    addNumber(unsigned int n);
        void    addNumber(const std::vector<int>& numbers);
        int     shortestSpan() const;
        int     longestSpan();
    
    protected:

    private:
    std::vector<int>    _container;
	unsigned int		_n;
};
