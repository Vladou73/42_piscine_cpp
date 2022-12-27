#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(0) {
    return;
}

HumanB::~HumanB(void) {
    return;
}

void    HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}

void    HumanB::attack(void) {
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}