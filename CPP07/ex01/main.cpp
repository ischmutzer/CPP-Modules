#include "iter.hpp"
#include <iostream>
#include <typeinfo>

template <typename T>
void	print(T& element) {
		std::cout << typeid(element).name() << " " << element << std::endl;
}

void	printString(std::string& str) {
	std::cout << str << " ";
}

void    printInt(int& x) {
    std::cout << x << " ";
}

void    printDouble(double& d) {
    std::cout << d << " ";
}

template    <typename T>
void    multiplyByTwo(T& num) {
    num *= 2;
    std::cout << num << " ";
}

int main() {
    std::string strs[4] = {"hola", "hello", "hallo", "chao"};
    int         num[4] = {2, 4, 6, 8};
    double      d[4] = {2.2, 1.5, 6.6, 10.8};

    std::cout << "String array = ";
    iter(strs, 4, printString);
    std::cout << "Int array = ";
    iter(num, 4, printInt);
    std::cout << "Double array = ";
    iter(d, 4, printDouble);

    std::cout << "Int x 2 = ";
    iter(num, 4, multiplyByTwo<int>);
    std::cout << "Double x 2 = ";
    iter(d, 4, multiplyByTwo<double>);

    return 0;
}