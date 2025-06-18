#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <string>

template <typename container>
class Sorter {
    public:
        // Sorter(/* args */);
        // ~Sorter();
        void    sort(container& sequence) {
            fordJohnsonSort(sequence.begin(), sequence.end());
        }
    private:

        std::deque<int>  generateInsertionOrderFromBoundaries(const std::deque<int>& boundaries, size_t size) {
            std::deque<int> insertOrder(size);

            if (size < 2 || boundaries.size() < 2)
                //throw   std::logic_error("ERROR: Insufficient size for Ford-Johnson insertion order.");

            insertOrder[0] = boundaries[0]; //we skip index 0 since it'll be inserted without comparison
            insertOrder[1] = boundaries[1]; //add  checks to indexOrderGen() to make sure this doesnt read random memory

            for (size_t i = 2, k = 2; i < size;) {
                for (int a = boundaries[k - 1]; --a > boundaries[k - 2];) { //pre decrement doesnt work if in 3rd pos bc 3rd pos gets exec after loop body runs
                    insertOrder[i++] = a;
                }
                if (k < boundaries.size()) {
                    insertOrder[i++] = boundaries[k++];
                } else {
                    break;
                }
            }
            return insertOrder;
        }

        template<typename T>
        std::deque<T>  indexOrderGenerator(size_t size) {
            std::deque<T>  order;
            order.resize(size + 1);
        
            if (order.size() == 0) {
                throw std::range_error("ERROR: Invalid/Empty deque passed to indexOrderGenerator.");
            }

            if (size >= 1)
                order[0] = 1;
            if (size >= 2)
                order[1] = 3;
            
            for (size_t i = 2; i < size; i++) {
                order[i] = order[i - 1] + 2 * order[i - 2];
            }
            return generateInsertionOrderFromBoundaries(order, size);
        }
    
        template<typename iterator>
        void    fordJohnsonSort(iterator first, iterator last, int depth = 1) { // depth is used for debugging purposes

            /* if (first >= last) {
                throw std::range_error("ERROR: Invalid/Empty iterator passed to Ford-Johnson sorter.");
            } */
            if (std::distance(first, last) <= 1) {
                 return;
                }

            typedef typename std::iterator_traits<iterator>::value_type T;
    
            std::deque<T>  largeE, smallE;
            iterator it =   first;
            while (it + 1 < last) {
                if (*it < *(it + 1)) {
                    largeE.push_back(*(it + 1));
                    smallE.push_back(*it);
                } else {
                    largeE.push_back(*it);
                    smallE.push_back(*(it + 1));
                }
                it += 2;
            }

            //handle odd element
            if (it < last) {
                smallE.push_back(*it);
            }

            //basecase
            if (!largeE.empty()) {
                fordJohnsonSort(largeE.begin(), largeE.end(), depth + 1);
            }

//DEBUGGING
            std::string indent(depth * 2, ' ');
            std::cout << indent << "Iteration " << depth << " largeE = {";
            for (typename std::deque<T>::const_iterator it1 = largeE.begin(); it1 < largeE.end(); it1++) {
                std::cout << *it1 << ", "; 
            }
            std::cout << "}" << std::endl;

            std::cout << indent << "Iteration " << depth << " smallE = {";
            for (typename std::deque<T>::const_iterator it2 = smallE.begin(); it2 < smallE.end(); it2++) {
                std::cout << *it2 << ", "; 
            }
            std::cout << "}\n" << std::endl;
//DEBUGGING

            //jacobstahl
            std::deque<int>    order = indexOrderGenerator<int>(smallE.size());
            std::cout << " --Beginning--" << std::endl;
            for (size_t i = 0; i < order.size(); i++) {
                std::cout << "order[" << i << "] =" << order[i] << std::endl;
            }
            std::cout << " --End--" << std::endl;
            //largeE.push_front(smallE[0]);
            //std::copy(largeE.begin(), largeE.end(), first);

           /*  std::string indent2(depth * 2, ' ');
            std::cout << indent2 << "(Going Back) Iteration " << depth << " largeE = {";
            for (typename std::deque<T>::const_iterator it1 = largeE.begin(); it1 < largeE.end(); it1++) {
                std::cout << *it1 << ", "; 
            }
            std::cout << "}" << std::endl;
            
            std::cout << indent << "(Going Back) Iteration " << depth << " smallE = {";
            for (typename std::deque<T>::const_iterator it2 = smallE.begin(); it2 < smallE.end(); it2++) {
                std::cout << *it2 << ", "; 
            }
            std::cout << "}\n" << std::endl;
            std::cout << "\n-------------------\n" << std::endl; */
            
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
        void                processInput(const std::string& str);
        std::vector<int>    getVect();
        std::deque<int>     getDeque();
        
    private:
    
    bool    hasDuplicates() const;
    bool    isSpace(const char& c);
    bool    isDigit(const char& c);
    void    convertAndStoreSequence(const std::string& str);
    void    insertionSequenceGenerator();

    std::vector<int>    _vect;
    std::vector<int>    _tmpVect;

    std::deque<int>     _deque;
    std::deque<int>     _tmpDeque; //can access any element in the deque with .at() or []

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
