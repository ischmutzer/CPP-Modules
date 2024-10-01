#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

/* int main () {
    Weapon club = Weapon("crude spiked club");
    //std::cout << "selected weapon is " << club.getType() << std::endl;
    //club.setType("some other type of club");
    //std::cout << "selected weapon is " << club.getType() << std::endl;

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
}
 */
int main()
{
    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");

        HumanB jim("Jim");
        jim.setWeapon(&club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    {
        HumanB ali("Ali");
        ali.attack();
    }
    return 0;
}
