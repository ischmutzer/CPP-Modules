#include "PmergeMe.hpp"
#include <algorithm>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& source) { *this = source; }

PmergeMe&   PmergeMe::operator=(const PmergeMe& source) {
    if (this != &source) {
        _vect       = source._vect;
        _tmpVect    = source._tmpVect;
        _deque      = source._deque;
        _tmpDeque   = source._tmpDeque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool    PmergeMe::isSpace(const char& c) {
    return std::isspace(c);
}


//TO CONSIDER: accept num with leading '+'?
bool    PmergeMe::isDigit(const char& c) {
    /* if (!(isSpace(c)) && (c >= '9' || c <= '0'))
        return false;
    else
        return true; */

    return std::isdigit(c);
}

bool    PmergeMe::hasDuplicates() const {
    for (unsigned int i = 0; i < _vect.size(); ++i) {
        for (unsigned int j = i + 1; j < _vect.size(); ++j) {
            if (_vect[i] == _vect[j])
                return true;
        }
    }
    return false;
}

void    PmergeMe::convertAndStoreSequence(const std::string& str) {
    std::istringstream  iss(str);
    int                 num;

    while (iss >> num) {
        if (iss.fail()) {
            throw std::runtime_error("ERROR: fail bit set.");
        }
        _vect.push_back(num);
        _deque.push_back(num);
    }
    if (iss.fail() && !iss.eof()) {
        throw std::runtime_error("ERROR: istringstream() failed.");
    }
    if (hasDuplicates())
        throw std::logic_error("ERROR: Duplicate detected.");
}

std::vector<int>    PmergeMe::getVect() {
    return _vect;
}

std::deque<int>     PmergeMe::getDeque() {
    return _deque;
}

void    PmergeMe::processInput(const std::string& str) {
   for (unsigned int i = 0; i < str.size(); ++i) {
        if (!(isDigit(str[i])) && !(isspace(str[i])))
            throw   std::invalid_argument("ERROR: Invalid input. Expected input: positive integer.");
    }
    convertAndStoreSequence(str);
}

void    PmergeMe::printSequenceVector(const std::vector<int>& sequence, const std::string& tag) {
    std::cout << tag;
    for (size_t i = 0; i < sequence.size(); ++i) {
        if (i < 4 || sequence.size() <= 8) {
            std::cout << sequence[i] << " ";
        } else if (i == 4) {
            std::cout << "[...] ";
            break;
        }
    }
    std::cout << std::endl;
}

void    PmergeMe::printSequenceDeque(const std::deque<int>& sequence, const std::string& tag) {
    std::cout << tag;
    for (size_t i = 0; i < sequence.size(); ++i) {
        if (i < 4 || sequence.size() <= 8) {
            std::cout << sequence[i] << " ";
        } else if (i == 4) {
            std::cout << "[...] ";
            break;
        }
    }
    std::cout << std::endl;
}

void    PmergeMe::sortPrintVector() {
    Sorter<std::vector<int> >   v;
    printSequenceVector(_vect, "Before ");

    std::clock_t	start = std::clock();
	v.sort(_vect);
	std::clock_t	end = std::clock();

	double	eSecs = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	
    printSequenceVector(_vect, "After: ");
	std::cout << "Time to process a range of " << _vect.size() << " elements with std::vector : " << eSecs << " us" << std::endl;
}

void    PmergeMe::sortPrintDeque() {
    Sorter<std::deque<int> >	d;
    printSequenceDeque(_deque, "Before: ");

	std::clock_t	start = std::clock();
	d.sort(_deque);
	std::clock_t	end = std::clock();

	double	eSecs = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	
    printSequenceDeque(_deque, "After: ");
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << eSecs << " us" << std::endl;
}
