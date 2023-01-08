#include "Animal.hpp"

// **************** CANONICAL CLASS FUNCTIONS **************** //

Animal::Animal(void): _type("Unknown") {
    std::cout << "Animal constructor called" << std::endl;
    return;
}
Animal::Animal(std::string type): _type(type) {
    std::cout << "Animal constructor called" << std::endl;
    return;
}
Animal::~Animal(void) {
    std::cout << "Animal destructor called " << std::endl << std::endl;
    return;
}

Animal::Animal(Animal const & toCopy) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = toCopy;
    return;
}

Animal& Animal::operator=(Animal const & toCopy) {
    if (this == &toCopy)
        return *this;
    this->_type = toCopy._type;
    return *this;
}

// **************** MEMBER FUNCTIONS **************** //
void    Animal::makeSound(void) const {
    std::cout << "unidentified animal makes a weird sound" << std::endl;
    return;
}
std::string    Animal::getType(void) const {
    return this->_type;
}
