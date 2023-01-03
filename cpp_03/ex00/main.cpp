#include "ClapTrap.hpp"

int main(void) {
    ClapTrap trap1("John");
    ClapTrap trap2("Elsa");

    trap1.beRepaired(2);
    trap2.attack("Girafe");
    trap1.takeDamage(3);

    return 0;
}