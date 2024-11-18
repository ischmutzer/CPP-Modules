#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class   DiamondTrap : public FragTrap, public ScavTrap {
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& source);
        DiamondTrap&    operator=(const DiamondTrap& source);
        ~DiamondTrap();

        void    whoAmI();
        void    attack(std::string target);
        
    private:
        std::string _name;
};

#endif