#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {   
    return; 
}

Weapon::~Weapon(void) {
    return;
}

const std::string &Weapon::getType(void) const{
    return _type;
}

void Weapon::setType(std::string const &type) {
    _type = type;
}