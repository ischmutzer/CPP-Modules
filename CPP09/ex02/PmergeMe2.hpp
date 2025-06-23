#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>

class VectorSorter {
    public:
        void    sort(std::vector<int>& sequence);
    private:
        static const size_t _boundariesSize = 38;
        static const size_t _boundaries[_boundariesSize];

        std::deque<size_t>  genInsertOrder(size_t size);

};