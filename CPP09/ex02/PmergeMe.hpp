#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>

template <typename container>
class Sorter {
    public:
        Sorter() {};
        Sorter(const Sorter& source) { *this = source; };
        Sorter& operator=(const Sorter& source) {
            if (this != &source) {
                _comparisonCounter = source._comparisonCounter;
            }
            return *this;
        };
        ~Sorter() {};

        void    sort(container& sequence) {
            fordJohnsonSort(sequence.begin(), sequence.end());
        }
        size_t                  _comparisonCounter;

    private:

        static const size_t     _jacobstahlBoundariesSize = 38;
        static const size_t     _boundaries[_jacobstahlBoundariesSize];


        std::vector<size_t> genInsertOrder(size_t size){
            std::vector<size_t> order;
            
            size_t  last = 0;
            size_t  n = 0;
            size_t  jacobstahlNum;
            size_t  i = size;
            
            while (i > 0) {
                jacobstahlNum = _boundaries[n];
                if (jacobstahlNum > size)
                    jacobstahlNum = size;
                size_t current = jacobstahlNum;
                while (current > last && i > 0) {
                    order.push_back(current);
                    current--;
                    i--;
                }
                last = jacobstahlNum;
                n++;
            } 
            return order;
        }

        template<typename iterator, typename T>
        iterator binarySearch(iterator first, iterator last, const T& value) {
            while (first < last) {
                iterator mid = first + (last - first) / 2;

                _comparisonCounter++;
                if (*mid < value) {
                    first = mid + 1;
                } else {
                    last = mid;
                }
            }
            return first;
        }

        template<typename iterator>
        void fordJohnsonSort(iterator first, iterator last) { //for debugging add -> , int depth = 1 // to track recursion layers
        size_t  n = std::distance(first, last);

        //basecase
        if (n <= 1) return;
        if (n == 2) {
            _comparisonCounter++;
            if (*first > *(first + 1)) {
                std::iter_swap(first, first + 1);
            }
            return;
        }

        typedef typename std::iterator_traits<iterator>::value_type T;
    
        //store pairs to achieve mirroring -> index tracking
        std::vector<std::pair<T, T> > pairs; // (large, small)
        T oddElement;
        bool hasOdd = false;

        iterator it = first;
        while (it + 1 < last) {
            T   a = *it;
            T   b = *(it + 1);
            if (a < b) {
                pairs.push_back(std::make_pair(b, a));
            } else {
                pairs.push_back(std::make_pair(a, b));
            }
            it += 2;
            _comparisonCounter++;
        }

        //handle odd element
        if (it < last) {
            oddElement = *it;
            hasOdd = true;
        }

        //adding large elements into largeE to sort recursively
        std::vector<T> largeE;
        for (size_t i = 0; i < pairs.size(); ++i) {
            largeE.push_back(pairs[i].first);
        }
        
        fordJohnsonSort(largeE.begin(), largeE.end());

        //largeE gets modified bc its a copy of first, so we need to reorder pairs according to the newly sorted large elements
        std::vector<std::pair<T, T> > sortedPairs;
        for (size_t i = 0; i < largeE.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].first == largeE[i]) {
                    sortedPairs.push_back(pairs[j]);
                    break;
                }
            }
        }
        pairs = sortedPairs;

        std::vector<T> merged;
        std::vector<bool> inserted(pairs.size() + (hasOdd ? 1 : 0), false);

        //insert index 0
        merged.push_back(pairs[0].second);
        inserted[0] = true;

        //looping through pairs and inserting all large elements
        for (size_t i = 0; i < pairs.size(); ++i) {
            merged.push_back(pairs[i].first);
        }

        std::vector<size_t> insertOrder = genInsertOrder(pairs.size() + (hasOdd ? 1 : 0));

        for (size_t i = 0; i < insertOrder.size(); ++i) {
            size_t index = insertOrder[i];

            if (index < pairs.size()) {
                T valueToInsert = pairs[index].second;

                typename std::vector<T>::iterator largePos = std::find(merged.begin(), merged.end(), pairs[index].first);

                typename std::vector<T>::iterator pos = binarySearch(merged.begin(), largePos, valueToInsert);
                merged.insert(pos, valueToInsert);
                inserted[index] = true;
            } else if (hasOdd) {
                typename std::vector<T>::iterator pos = std::lower_bound(merged.begin(), merged.end(), oddElement);
                merged.insert(pos, oddElement);
                hasOdd = false;
                inserted[pairs.size()] = true;
            }
        }

        if (hasOdd) {
                typename std::vector<T>::iterator pos = binarySearch(merged.begin(), merged.end(), oddElement);
                merged.insert(pos, oddElement);
                hasOdd = false;
                inserted[pairs.size()] = true;
            }

        std::copy(merged.begin(), merged.end(), first);
    }
};


template <typename container>
const size_t Sorter<container>::_boundaries[Sorter<container>::_jacobstahlBoundariesSize] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763,
    349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971,
    357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123, 22906492245, 45812984491,
    91625968981, 183251937963};

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& source);
        PmergeMe& operator=(const PmergeMe& source);
        ~PmergeMe();

        void                processInput(const std::string& str);
        std::vector<int>    getVect();
        std::deque<int>     getDeque();
        void                printSequenceVector(const std::vector<int>& sequence, const std::string& tag);
        void                printSequenceDeque(const std::deque<int>& sequence, const std::string& tag);
        void                sortPrintVector();
        void                sortPrintDeque();

    private:
    
        bool    hasDuplicates() const;
        bool    isSpace(const char& c);
        bool    isDigit(const char& c);
        void    convertAndStoreSequence(const std::string& str);
    
        std::vector<int>    _vect;
        std::vector<int>    _tmpVect;
    
        std::deque<int>     _deque;
        std::deque<int>     _tmpDeque; //can access any element in the deque with .at() or []

};













//DEBUGGING MESSAGES


        // DEBUGGING
        /* std::cout << indent << "Insertion order: ";
        for (size_t i = 0; i < insertOrder.size(); ++i) {
            std::cout << insertOrder[i] << " ";
        }
        std::cout << std::endl; */
        // DEBUGGING


        // DEBUGGING
        /* std::cout << indent << "Final result: ";
        for (typename std::deque<T>::iterator it = merged.begin(); it != merged.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl; */
        // DEBUGGING


//DEBUGGING


//Deque vs Container

//deque (double ended queue) -> container thatv allows for fast insertion
// and deletion of elements at both ends of the sequence. Provides random
// access to elements.

//characterists:
// 1) efficient insertion and deletion at head and tail of container
// 2) random access with [] operator or .at() method
// 3) dynamic memory allocation (dynamic resizing) is supported by
//allocating additional blocks.
// 4) insertion and deletion at head/tail are fast
// 5) not contiguous block of memory.


//vector -> container that provides random access to its elements and supports
//dynamic resizing.

//characteristics:
// 1) stores elements in a single contiguous (sharing a common
//border; touching (adjacent)) block of memory. Very fast random access.
// 2) has fast access to the last element but slower for front and middle
//insertion and deletion due to need to shift elements.
// 3) dynamic resizing is supported by reallocating memory and copying
//all existing elements to a larger block.

//Conclusion
//Both vector and deque allow for dynamic resizing, however the different
//approach to how they allow for resizing may influence the performance
//of each container. Vector is preferred when the intent is to be able
//to quickly randomly access elements and appending elements at the back,
///if fast insertion and deletion is needed at the front and back of the
//container, deque is the more suitable option.

//In this case vector and deque were the better suited options for this
//exercise due to their random access functionality and dynamic resizing. 

//WHY PRE DECREMENT IN A FOR LOOP

//In a for loop the third pos will be executed after the loop, therefore whether
//you pre decrement or post decrement makes no difference in execution
//however when you decrese/increase after (i++) you make a copy of the old value
//which makes the (++i) in for loops a preferance in c++

//us stands for microseconds