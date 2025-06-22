#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <string>
#include <sstream>

template <typename container>
class Sorter {
    public:
        // Sorter(/* args */);
        // ~Sorter();
        void    sort(container& sequence) {
            fordJohnsonSort(sequence.begin(), sequence.end());
        }

    private:

        static const size_t     _jacobstahlBoundariesSize = 38;
        static const size_t     _boundaries[_jacobstahlBoundariesSize];

        std::deque<size_t> genInsertOrder(size_t size){
            std::deque<size_t> order;
            size_t last = 0;
            size_t n = 0;
            size_t  jacobstahlNum;
            size_t ogSize = size;
            
            while (size > 0) {
                jacobstahlNum = _boundaries[n];
                if (jacobstahlNum > ogSize)
                    jacobstahlNum = ogSize;
                size_t current = jacobstahlNum;
                while (current > last && size > 0) {
                    order.push_back(current);
                    current--;
                    size--;
                }
                last = jacobstahlNum;
                n++;
            } 
            return order;
        }

        //Main sorting ft
        template<typename iterator>
        void    fordJohnsonSort(iterator first, iterator last, int depth = 1) { // depth is used for debugging purposes

            //basecase
            if (std::distance(first, last) <= 1) return;

            typedef typename std::iterator_traits<iterator>::value_type T;
            std::deque<T>  largeE, smallE;

            iterator it = first;
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

            fordJohnsonSort(largeE.begin(), largeE.end(), depth + 1);
            
            std::vector<bool>   inserted(smallE.size(), false);

            std::deque<T> merged;
            merged.insert(merged.end(), largeE.begin(), largeE.end());

            typename std::deque<T>::iterator pos = std::lower_bound(merged.begin(), merged.end(), smallE[0]);
            merged.insert(pos, smallE[0]);
            inserted[0] = true;

            //std::deque<size_t> insertOrder = genInsertOrder(smallE.size());
            std::deque<size_t> insertOrder = genInsertOrder(largeE.size());

            for (size_t i = 0; i < insertOrder.size(); ++i) {
                size_t index = i < insertOrder.size() ? insertOrder[i] : i;
                if (index >= largeE.size()) index = i;

                T value = largeE[index];
                typename std::deque<T>::iterator    pos = std::lower_bound(merged.begin(), merged.end(), value);
                merged.insert(pos, )
            }
            /* for (size_t i = 1; i < insertOrder.size(); ++i) {
                size_t index = i < insertOrder.size() ? insertOrder[i] : i;
                if (index >= smallE.size()) index = i;

                if (inserted[index]) continue;
                inserted[index] = true;

                T value = smallE[index];
                typename std::deque<T>::iterator pos = std::lower_bound(merged.begin(), merged.end(), value);
                merged.insert(pos, value);
            } */
            std::copy(merged.begin(), merged.end(), first);
            
        }
};


template <typename container>
const size_t Sorter<container>::_boundaries[Sorter<container>::_jacobstahlBoundariesSize] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763,
    349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971,
    357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123, 22906492245, 45812984491,
    91625968981, 183251937963};


// template <typename container>
// class Sorter {
//     public:
//         // Sorter(/* args */);
//         // ~Sorter();
//         void    sort(container& sequence) {
//             fordJohnsonSort(sequence.begin(), sequence.end());
//         }
//     private:

//         static const size_t     _jacobstahlBoundariesSize = 38;
//         static const size_t     _boundaries[_jacobstahlBoundariesSize];

//         std::deque<size_t> genInsertOrder(size_t size){
//             std::deque<size_t> order;
//             size_t last = 0;
//             size_t n = 0;
//             size_t  jacobstahlNum;
//             size_t ogSize = size;
            
//             while (size > 0) {
//                 jacobstahlNum = _boundaries[n];
//                 if (jacobstahlNum > ogSize)
//                     jacobstahlNum = ogSize;
//                 size_t current = jacobstahlNum;
//                 while (current > last && size > 0) {
//                     order.push_back(current);
//                     current--;
//                     size--;
//                 }
//                 last = jacobstahlNum;
//                 n++;
//             } 
//             return order;
//         }
// /* 
//         std::vector<int> order;
// 	size_t lastJacNb = 0;
// 	size_t nJacNb = 0;
// 	size_t jacNb;
// 	size_t ogAmount = amount;

// 	while (amount > 0)
// 	{
// 		jacNb = _jacobsNb[nJacNb];
// 		if (jacNb > ogAmount)
// 			jacNb = ogAmount;
// 		size_t temp = jacNb;
// 		while (temp > lastJacNb && amount > 0)
// 		{
// 			//std::cout << "temp: " << temp << " amount: " << amount << std::endl;
// 			order.push_back(temp);
// 			temp--;
// 			amount--;
// 		}
// 		lastJacNb = jacNb;
// 		nJacNb++;
// 	}

// 	return order; */
    
//         /* std::deque<int>  generateJacobstahlBoundaries(size_t size) {
//             std::deque<int>  order;

//             if (size >= 1) order.push_back(1);
//             if (size >= 2) order.push_back(3);

//             for (size_t i = 2; i < size; ++i) {
//                 int value = order[i - 1] + 2 * order[i - 2];
//                 if (value > static_cast<int>(size)) break;
//                 order.push_back(value);
//             }
//             return order;
//         } */

//         /* void print_que(std::deque<int> q) {
//             for (size_t i = 0; i<q.size(); i++)
//             {
//                 std::cout << q[i] << " ";
//             }
//             std::cout << std::endl;
//         } */

//         /* std::deque<int>  generateInsertionOrderFromBoundaries(const std::deque<int>& boundaries, size_t size) {
//             std::deque<int> insertOrder;

//             if (size < 2 || boundaries.size() < 2)
//                 return insertOrder;
//             //throw   std::logic_error("ERROR: Insufficient size for Ford-Johnson insertion order.");
//             // std::cout << "it thu boundaries" << std::endl;
//             // for (size_t i = 0; i < boundaries.size(); i++) {
//             //     std::cout << boundaries[i] << std::endl;
//             // }
//             // std::cout << "end it thu boundaries" << std::endl;
//             // std::cout << "size: " << size << std::endl;

//             insertOrder.push_back(boundaries[0]); //we skip index 0 since it'll be inserted without comparison
//             if (size > 1)
//                 insertOrder.push_back(boundaries[1]); //add  checks to make sure this doesnt read random memory

//             // std::cout << "after hand adding" << std::endl;
//             // for (size_t i = 0; i < boundaries.size(); i++) {
//             //     std::cout << "boundary: " << boundaries[i] << std::endl;
//             // }

//             for (size_t k = 2; insertOrder.size() < size;) {
//                 for (int a = boundaries[k - 1] - 1; a > boundaries[k - 2] && insertOrder.size() < size; --a) { //pre decrement doesnt work if in 3rd pos bc 3rd pos gets exec after loop body runs
//                     insertOrder.push_back(a);
//                 }
//                 if (k < boundaries.size() && insertOrder.size() < size) {
//                     insertOrder.push_back(boundaries[k++]);
//                 } else {
//                     break;
//                 }
//             }

//             // std::cout << "after loop adding" << std::endl;
//             // for (size_t i = 0; i < boundaries.size(); i++) {
//             //     std::cout << "boundary: " << boundaries[i] << std::endl;
//             // }


//             // std::cout << "insertOrder: " << insertOrder << std::endl;
//             return insertOrder;
//         } */

//         //Main sorting ft
//         template<typename iterator>
//         void    fordJohnsonSort(iterator first, iterator last, int depth = 1) { // depth is used for debugging purposes

//             /* if (first >= last) {
//                 throw std::range_error("ERROR: Invalid/Empty iterator passed to Ford-Johnson sorter.");
//             } */

//             //basecase
//             if (std::distance(first, last) <= 1) return;

//             typedef typename std::iterator_traits<iterator>::value_type T;
//             std::deque<T>  largeE, smallE;

//             iterator it = first;
//             while (it + 1 < last) {
//                 if (*it < *(it + 1)) {
//                     largeE.push_back(*(it + 1));
//                     smallE.push_back(*it);
//                 } else {
//                     largeE.push_back(*it);
//                     smallE.push_back(*(it + 1));
//                 }
//                 it += 2;
//             }

//             /* std::cout << "first split: " << std::endl;
//             std::cout << "largeE: " << std::endl;
//             print_que(largeE);
//             std::cout << "smallE: " << std::endl;
//             print_que(smallE); */

//             //handle odd element
//             if (it < last) {
//                 smallE.push_back(*it);
//             }
//             //DEBUGGING
//                         std::string indent(depth * 2, ' ');
//                         std::cout << indent << "Iteration " << depth << " largeE = {";
//                         for (typename std::deque<T>::const_iterator it1 = largeE.begin(); it1 < largeE.end(); ++it1) {
//                             std::cout << *it1 << ", "; 
//                         }
//                         std::cout << "}" << std::endl;
            
//                         std::cout << indent << "Iteration " << depth << " smallE = {";
//                         for (typename std::deque<T>::const_iterator it2 = smallE.begin(); it2 < smallE.end(); ++it2) {
//                             std::cout << *it2 << ", "; 
//                         }
//                         std::cout << "}\n" << std::endl;
//             //DEBUGGING

//             fordJohnsonSort(largeE.begin(), largeE.end(), depth + 1);
            
//             std::vector<bool>   inserted(smallE.size(), false);
//             std::deque<T> merged;
//             //merged.push_back(smallE[0]);
//             merged.insert(merged.end(), largeE.begin(), largeE.end());
//             typename std::deque<T>::iterator pos = std::lower_bound(merged.begin(), merged.end(), smallE[0]);
// merged.insert(pos, smallE[0]);
//             inserted[0] = true;

//             //std::deque<int> boundaries = generateJacobstahlBoundaries(smallE.size());

//             //DEBUGGING
//                         // std::cout << "\nBOUNDARIES\n";
//                         // for (size_t i = 0; i < boundaries.size(); ++i) {
//                         //     std::cout << boundaries[i] << " ";
//                         // }
//                         // std::cout << std::endl;
//             //DEBUGGING

//             //std::deque<int> insertOrder = generateInsertionOrderFromBoundaries(_boundaries, smallE.size());
//             std::deque<size_t> insertOrder = genInsertOrder(smallE.size());
//             //DEBUGGING
//                         std::cout << "\nINSERTION ORDER\n";
//                         for (size_t i = 0; i < insertOrder.size(); ++i) {
//                             std::cout << insertOrder[i] << " ";
//                         }
//                         std::cout << std::endl;
//             //DEBUGGING

//             for (size_t i = 1; i < insertOrder.size(); ++i) {
//                 size_t index = i < insertOrder.size() ? insertOrder[i] : i;
//                 if (index >= smallE.size()) index = i;

//                 if (inserted[index]) continue;
//                 inserted[index] = true;

//                 T value = smallE[index];
//                 typename std::deque<T>::iterator pos = std::lower_bound(merged.begin(), merged.end(), value);
//                 merged.insert(pos, value);
//             }
//             //DEBUGGING
//                     /* std::cout << "\nMERGED\n";
//                     for (size_t i = 0; i < merged.size(); ++i) {
//                         std::cout << merged[i] << " ";
//                     }
//                     std::cout << std::endl;*/
//             //DEBUGGING
//             std::copy(merged.begin(), merged.end(), first);

// //DEBUGGING
//                         std::string indent2(depth * 2, ' ');
//                         std::cout << indent2 << "Iteration " << depth << " largeE = {";
//                         for (typename std::deque<T>::const_iterator it1 = largeE.begin(); it1 < largeE.end(); ++it1) {
//                             std::cout << *it1 << ", "; 
//                         }
//                         std::cout << "}" << std::endl;
            
//                         std::cout << indent2 << "Iteration " << depth << " smallE = {";
//                         for (typename std::deque<T>::const_iterator it2 = smallE.begin(); it2 < smallE.end(); ++it2) {
//                             std::cout << *it2 << ", "; 
//                         }
//                         std::cout << "}\n" << std::endl;
//             //debugging
            
//         }
// };


// template <typename container>
// const size_t Sorter<container>::_boundaries[Sorter<container>::_jacobstahlBoundariesSize] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763,
//     349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971,
//     357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123, 22906492245, 45812984491,
//     91625968981, 183251937963};


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

//WHY PRE DECREMENT IN A FOR LOOP

//In a for loop the third pos will be executed after the loop, therefore whether
//you pre decrement or post decrement makes no difference in execution
//however when you decrese/increase after (i++) you make a copy of the old value
//which makes the (++i) in for loops a preferance in c++