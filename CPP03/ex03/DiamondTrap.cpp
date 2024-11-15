#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() {
    std::cout << "DiamnondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& source) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& source) {
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}