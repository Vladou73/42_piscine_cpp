#include "WrongAnimal.hpp"

// **************** CANONICAL CLASS FUNCTIONS **************** //

WrongAnimal::WrongAnimal(void): _type("Unknown") {
    std::cout << "WrongAnimal constructor called" << std::endl;
    return;
}
WrongAnimal::WrongAnimal(std::string type): _type(type) {
    std::cout << "WrongAnimal constructor called" << std::endl;
    return;
}
WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal destructor called " << std::endl << std::endl;
    return;
}

WrongAnimal::WrongAnimal(WrongAnimal const & toCopy) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = toCopy;
    return;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & toCopy) {
    if (this == &toCopy)
        return *this;
    this->_type = toCopy._type;
    return *this;
}

// **************** MEMBER FUNCTIONS **************** //
void    WrongAnimal::makeSound(void) const {
    std::cout << "unidentified WrongAnimal makes a weird sound" << std::endl;
    return;
}
std::string    WrongAnimal::getType(void) const {
    return this->_type;
}
