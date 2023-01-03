//However, its constructors, destructor and attack() will print different messages.
//After all, ClapTraps are aware of their individuality.
#include "ScavTrap.hpp"

// **************** CANONICAL CLASS FUNCTIONS **************** //

ScavTrap::ScavTrap(void): ClapTrap() {
    this->_hit_pts = 100;
    this->_energy_pts = 50;
    this->_attack_dmg = 20;
    
    std::cout << "DEFAULT ScavTrap constructor called" << std::endl;
    return;
}
ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap destructor called" << std::endl;
    return;
}
ScavTrap::ScavTrap(std::string const & name): ClapTrap(name, 100, 50, 20) {
    std::cout << "ScavTrap constructor called, name assigned : " << name << std::endl;
    return;
}
ScavTrap::ScavTrap(ScavTrap const & toCopy): ClapTrap(toCopy) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = toCopy;
    return;
}
ScavTrap& ScavTrap::operator=(ScavTrap const & toCopy) {
    if (this == &toCopy)
        return *this;
    this->_attack_dmg = toCopy._attack_dmg;
    this->_energy_pts = toCopy._energy_pts;
    this->_hit_pts = toCopy._hit_pts;
    this->_name = toCopy._name;
    return *this;    
}


// **************** OTHER MEMBER FUNCTIONS **************** //

void ScavTrap::guardGate(void) {
    std::cout << this->_name << " is now in Gate keeper mode" << std::endl; 
}