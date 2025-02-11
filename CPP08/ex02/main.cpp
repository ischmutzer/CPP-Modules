#include "MutantStack.hpp"
#include <list>
#include <iostream>

//subject main
/* int main()
{
	//MutantStack<int> mstack;
	std::list<int>	myList;

	// mstack.push(5);
	// mstack.push(17);
	myList.push_back(5);
    myList.push_back(17);

	//std::cout << mstack.top() << std::endl;
	std::cout << myList.back() << std::endl;

	//mstack.pop();
	myList.pop_back();

	//std::cout << mstack.size() << std::endl;
	std::cout << myList.size() << std::endl;

	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	////[...]
	//mstack.push(0);
	 myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    // [...]
    myList.push_back(0);

	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	std::list<int>::iterator it = myList.begin();
    std::list<int>::iterator ite = myList.end();

	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}

	//std::stack<int> s(mstack);
	std::list<int> s(myList);
	return 0;
} */

#include <cassert>

int main() {
    // Testing the basic MutantStack with integers
    std::cout << "Testing basic MutantStack operations...\n";
    
    // Create a stack and add some elements
    MutantStack<int> stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    
    std::cout << "Top of stack after pushes: " << stack.top() << std::endl; // Should print 40

    // Pop the top element
    stack.pop();
    std::cout << "Top of stack after pop: " << stack.top() << std::endl; // Should print 30

    // Test iteration using begin() and end()
    std::cout << "Iterating over stack contents:\n";
    for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";  // Should print: 10 20 30
    }
    std::cout << "\n";

    // Create another stack using the copy constructor
    MutantStack<int> copiedStack(stack);
    std::cout << "Top of copied stack: " << copiedStack.top() << std::endl; // Should print 30

    // Create another stack and use the assignment operator
    MutantStack<int> assignedStack;
    assignedStack = stack;
    std::cout << "Top of assigned stack: " << assignedStack.top() << std::endl; // Should print 30


    // Test iterating over an empty stack
	MutantStack<int>	emptyStack;
    std::cout << "Iterating over an empty stack...\n";
    for (MutantStack<int>::iterator it = emptyStack.begin(); it != emptyStack.end(); ++it) {
        std::cout << *it << " ";  // Should not print anything
    }
    std::cout << std::endl;

    // Edge case: large stack (testing performance)
    std::cout << "Testing large stack...\n";
    MutantStack<int> largeStack;
    for (int i = 0; i < 10000; ++i) {
        largeStack.push(i);
    }
    std::cout << "Top of large stack: " << largeStack.top() << std::endl; // Should print 9999

    // Iterate over large stack and check for correctness
    int count = 0;
    for (MutantStack<int>::iterator it = largeStack.begin(); it != largeStack.end(); ++it) {
        assert(*it == count);  // Assert that the elements are in correct order
        count++;
    }

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}
