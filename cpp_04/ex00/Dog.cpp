#include "Dog.hpp"

// **************** CANONICAL CLASS FUNCTIONS **************** //

Dog::Dog(void): _type("Dog") {
    std::cout << "Dog constructor called" << std::endl << std::endl;
    return;
}
Dog::~Dog(void) {
    std::cout << "Dog destructor called " << std::endl;
    return;
}

Dog::Dog(Dog const & toCopy): Animal(toCopy) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = toCopy;
    return;
}

Dog& Dog::operator=(Dog const & toCopy) {
    if (this == &toCopy)
        return *this;
    this->_type = toCopy._type;
    return *this;    
}

// **************** MEMBER FUNCTIONS **************** //
void    Dog::makeSound(void) const {
    std::cout << "BARK BARK BARK" << std::endl;
    return;
}
std::string    Dog::getType(void) const {
    return this->_type;
}