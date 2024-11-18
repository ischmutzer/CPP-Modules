#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Base", 100, 50, 30) , FragTrap(), ScavTrap() {
    std::cout << "DiamnondTrap default constructor called" << std::endl;
    _name = "_" + this->getName();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name, 100, 50, 30), FragTrap(), ScavTrap() {
    std::cout << "Parameterized constructor called" << std::endl;
    _name = "_" + name;
}

 DiamondTrap::DiamondTrap(const DiamondTrap& source) {
     std::cout << "DiamondTrap copy constructor called" << std::endl;
 }

 DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& source) {
     std::cout << "DiamondTrap copy assignment operator called" << std::endl;
     return *this;
 }

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void    DiamondTrap::attack(std::string target) {
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap " << _name << " ClapTrap: " << ClapTrap::getName() << std::endl;
}


//NOTES:

//Diamond problem

//You want: (Achievable with virtual inheritance)
//  A  
// / \. 
//B   C  
// \ /  
//  D 

// And not: (What happens without virtual inheritance)
// A   A  
// |   |
// B   C  
//  \ /  
//   D 

//Virtual inheritance means there will only be one instance of base class A
//B::A and C::A are the same so no ambiguous calls can be made from D.
//otherwise without virtual inheritance you have the second diagram
//and need to specify which path you need to take
