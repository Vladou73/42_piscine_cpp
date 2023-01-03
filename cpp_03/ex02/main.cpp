#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    ScavTrap trap3("Lou");
    ScavTrap trap4("Ji");
    ScavTrap trap5(trap4);

    trap4.attack("Lou");
    trap3.takeDamage(20);    
    trap5.guardGate();

    std::cout << std::endl << std::endl ; 

    FragTrap trap6("Tim");
    FragTrap trap7("Jane");
    FragTrap trap8(trap6);

    trap7.attack("Lou");
    trap3.takeDamage(30);    
    trap8.highFivesGuys();

    return 0;
}