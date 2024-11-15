#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Base", 100, 100, 30) {
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
    std::cout << "FragTrap parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& source) : ClapTrap(source) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& source) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &source) {
        ClapTrap::operator=(source);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->getName() << " requests a five high" << std::endl;
}
