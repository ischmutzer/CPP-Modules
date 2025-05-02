#pragma once

#include <vector>
#include <string>
#include <stdexcept>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& source);
        PmergeMe& operator=(const PmergeMe& source);
        ~PmergeMe();

        //mergeInsert();
        //twoFingerAlgo();
        bool    isSpace(const char& c);
        bool    isDigit(const char& c);
        void    processInput(const std::string& str);

    private:
    std::vector<int>    _array;
    std::vector<int>    _tmpArray;
}
