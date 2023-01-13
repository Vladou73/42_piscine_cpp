#include "ClapTrap.hpp"

int main(void) {
    ClapTrap trap1("John");
    ClapTrap trap2("Elsa");

    std::cout << std::endl << std::endl;

    trap2.attack("Girafe");
    trap2.attack("Girafe");
    trap2.attack("Girafe");
    trap2.attack("Girafe");
    trap2.attack("Girafe");
    trap2.attack("Girafe");
    trap2.attack("Girafe");
    trap2.attack("Girafe");
    trap2.attack("Girafe");
    trap2.attack("Girafe");
    trap2.attack("Girafe");
    trap2.attack("Girafe");

    std::cout << std::endl << std::endl;

    trap1.takeDamage(3);
    trap1.beRepaired(2);
    trap1.beRepaired(2);
    trap1.beRepaired(2);

    std::cout << std::endl << std::endl;

    return 0;
}
