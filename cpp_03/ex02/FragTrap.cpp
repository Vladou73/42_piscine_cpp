#include "FragTrap.hpp"

// **************** CANONICAL CLASS FUNCTIONS **************** //

FragTrap::FragTrap(void): ClapTrap() {
    this->_hit_pts = 100;
    this->_energy_pts = 100;
    this->_attack_dmg = 30;
    
    std::cout << "DEFAULT FragTrap constructor called" << std::endl << std::endl;
    return;
}
FragTrap::~FragTrap(void) {
    std::cout << "FragTrap destructor called" << std::endl;
    return;
}
FragTrap::FragTrap(std::string const & name): ClapTrap(name, 100, 100, 30) {
    std::cout << "FragTrap constructor called, name assigned : " << name << std::endl << std::endl;
    return;
}
FragTrap::FragTrap(FragTrap const & toCopy): ClapTrap(toCopy) {
    std::cout << "FragTrap copy constructor called" << std::endl << std::endl;
    *this = toCopy;
    return;
}
FragTrap& FragTrap::operator=(FragTrap const & toCopy) {
    if (this == &toCopy)
        return *this;
    this->_attack_dmg = toCopy._attack_dmg;
    this->_energy_pts = toCopy._energy_pts;
    this->_hit_pts = toCopy._hit_pts;
    this->_name = toCopy._name;
    return *this;    
}


// **************** OTHER MEMBER FUNCTIONS **************** //

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap positive high fives !" << std::endl << std::endl; 
}