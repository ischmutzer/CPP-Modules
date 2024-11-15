#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include <string>

class   DiamondTrap {
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap& source);
        DiamondTrap&    operator=(const DiamondTrap& source);
        ~DiamondTrap();
        
    private:
        std::string _name;
};

#endif