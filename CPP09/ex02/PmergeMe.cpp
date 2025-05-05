#include "PmergeMe.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>

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
    if (!(isSpace(c)) && (c > '9' || c < '0'))
        return false;
    else
        return true;
}

bool    PmergeMe::hasDuplicates() const {
    for (unsigned int i = 0; i < _vect.size(); i++) {
        for (unsigned int j = i + 1; j < _vect.size(); j++) {
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

//./exec 123 "12 2 4"
void    PmergeMe::processInput(const std::string& str) {
   for (unsigned int i = 0; i < str.size(); i++) {
        if (!(isDigit(str[i])))
            throw   std::invalid_argument("ERROR: Invalid input. Expected input: positive integer.");
    }
    convertAndStoreSequence(str);
    std::cout << "Vector: ";
    for (unsigned int i = 0; i < _vect.size(); i++)
        std::cout << _vect[i] << " ";
    std::cout << std::endl;
    std::cout << "Deque: ";
    for (unsigned int i = 0; i < _deque.size(); i++) {
        std::cout << _deque[i] << " ";
    }
    std::cout << std::endl;
}

/* void PmergeMe::mergeInsert() {
    //divide and conquer
    //two finger algorithm
} */
