#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <string>

template <typename container>
class fordJohnsonSorter {
    public:
        // fordJohnsonSorter(/* args */);
        // ~fordJohnsonSorter();
        void    sort(container& sequence) {
            fordJohnsonSort(sequence);
        }
    private:
        typedef typename container::iterator    it;

        std::pair    pairNumbers(int a, int b) {
            if (a > b)
                std::make_pair(a, b);
            else
                std::make_pair(b, a);
        }

        void    fordJohnsonSort(container& sequence) {
            container   A;
            container   B;
            for (size_t i = 0; i < sequence.size(); i++) {
                A = pairNumbers(sequence[i], sequence[i + 1]);
            }
        }
};

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& source);
        PmergeMe& operator=(const PmergeMe& source);
        ~PmergeMe();

        //mergeInsert();
        //twoFingerAlgo();
        void    processInput(const std::string& str);
        
    private:
    
    bool    hasDuplicates() const;
    bool    isSpace(const char& c);
    bool    isDigit(const char& c);
    void    convertAndStoreSequence(const std::string& str);
    void    insertionSequenceGenerator();

    std::vector<int>    _vectA;
    std::vector<int>    _vectB;

    std::deque<int>     _dequeA;
    std::deque<int>     _dequeB; //can access any element in the deque with .at() or []

};


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
