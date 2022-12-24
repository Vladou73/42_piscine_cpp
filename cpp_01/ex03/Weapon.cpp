#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(void) {    
}
Weapon::~Weapon(void) {
}

const std::string &getType(void) {
    return _type;
}

void setType(std::string const &type) {
    _type = type;
}