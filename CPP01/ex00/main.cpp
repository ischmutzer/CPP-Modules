#include "Zombie.hpp"

int main() {
    //stack allocated Zombie -> scope ends when main is finished
    Zombie  zombieObject("Esteban");
    zombieObject.announce();

    //stack allocated Zombie -> scope ends after randomChump is exited
    randomChump("Benito");

    //heap allocated Zombie -> heapZombie is manually deleted
    Zombie* heapZombie = newZombie("Nico");
    heapZombie->announce();
    delete heapZombie;
    return 0;
}