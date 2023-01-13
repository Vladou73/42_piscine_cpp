#include "ClapTrap.hpp"

// **************** CANONICAL CLASS FUNCTIONS **************** //

ClapTrap::ClapTrap(void) {
    std::cout << "DEFAULT constructor called" << std::endl;
    return;
}
ClapTrap::~ClapTrap(void) {
    std::cout << "destructor called for : " << this->_name << std::endl;
    return;
}
ClapTrap::ClapTrap(std::string const & name): _name(name), _hit_pts(10), _energy_pts(10), _attack_dmg(0) {
    std::cout << "constructor called, name assigned : " << name << std::endl;
    return;
}
ClapTrap::ClapTrap(ClapTrap const & toCopy) {
    std::cout << "copy constructor called" << std::endl;
    *this = toCopy;
    return;
}
ClapTrap& ClapTrap::operator=(ClapTrap const & toCopy) {
    if (this == &toCopy)
        return *this;
    this->_attack_dmg = toCopy._attack_dmg;
    this->_energy_pts = toCopy._energy_pts;
    this->_hit_pts = toCopy._hit_pts;
    this->_name = toCopy._name;
    return *this;
}

// **************** MEMBER FUNCTIONS **************** //

void ClapTrap::attack(const std::string& target) {
    if (this->_energy_pts < 1) {
        std::cout << "NO ENERGY POINTS LEFT, CANNOT ATTACK" << std::endl;
        return;
    }
    if (this->_hit_pts < 1) {
        std::cout << "NO HIT POINTS LEFT, CANNOT ATTACK" << std::endl;
        return;
    }
    this->_energy_pts--;
    if (_energy_pts < 0)
        _energy_pts = 0;
    std::cout   << this->_name << " attacks " << target
                << " causing " <<  this->_attack_dmg << " points of damage!!!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    this->_hit_pts-= amount;
    if (_hit_pts < 0)
        _hit_pts = 0;
    std::cout << this->_name << " was attacked ! Hit points left : " << this->_hit_pts << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energy_pts < 1) {
        std::cout << "NO ENERGY POINTS LEFT, CANNOT REPAIR" << std::endl;
        return;
    }
    if (this->_hit_pts < 1) {
        std::cout << "NO HIT POINTS LEFT, CANNOT REPAIR" << std::endl;
        return;
    }
    if (this->_hit_pts > 9) {
        std::cout << "MAX HIT POINTS, CANNOT REPAIR" << std::endl;
        return;
    }
    this->_energy_pts--;
    this->_hit_pts+= amount;
    if (_hit_pts > 10)
        _hit_pts = 10;
    std::cout << this->_name << " auto-repair ! Hit points left : " << this->_hit_pts << std::endl;
}
