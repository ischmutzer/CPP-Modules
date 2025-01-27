#include "iter.hpp"
#include <iostream>

void	printArray(std::string& str) {
	std::cout << str << std::endl;
}

int main() {
    std::string strs[5] = {"hola", "hello", "hallo", "a"};

    iter(strs, 4, printArray);
    //iter(strs, 5, print);
    return 0;
}