#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& source) {}

PmergeMe&   PmergeMe::operator=(const PmergeMe& source) {}

PmergeMe::~PmergeMe() {}

bool    PmergeMe::isSpace(const char& c) {
    if (c == '\b' || c == '\t' || c == '\n')
        return true;
    else
        return false;
}

bool    PmergeMe::isDigit(const char& c) {
    if (!(isSpace(c)) && (c > '9' || c < '0'))
        return false;
    else
        true;
}

//./exec 123 "12 2 4"
void    PmergeMe::processInput(const std::string& str) {
    for (int i = 0; i < str.size(); i++) {
        if (!(isDigit(str[i])))
            throw   std::invalid_argument("ERROR: Invalid input. Expected input: positive integer.");
        //if a space is encountered -> parse  the str and store the digits
        //otherwise if str == +int then store directly
    }
    //check that argv[i] is a positive int if not throw an error
}

/* void PmergeMe::mergeInsert() {
    //divide and conquer
    //two finger algorithm
} */
