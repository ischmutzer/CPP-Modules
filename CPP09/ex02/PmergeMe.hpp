#pragma once

#include <vector>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& source);
        PmergeMe& operator=(const PmergeMe& source);
        ~PmergeMe();

    private:
    std::vector<int>    _array;
    std::vector<int>    _tmpArray;
}

