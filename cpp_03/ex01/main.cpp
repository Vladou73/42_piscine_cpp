#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    ClapTrap trap3("Lou");
    ScavTrap trap4("Ji");
    ScavTrap trap5(trap4);

    trap3.attack("Ji");
    trap4.attack("Lou");
    trap3.takeDamage(20);
    trap5.guardGate();

    return 0;
}
