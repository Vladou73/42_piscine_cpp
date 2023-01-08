#include "Dog.hpp"

// **************** CANONICAL CLASS FUNCTIONS **************** //

Dog::Dog(void): _type("Dog"), _brainPtr(0) {
    std::cout << "Dog constructor called" << std::endl << std::endl;
    _brainPtr = new Brain();
    _brainPtr->setIdea(0, "I am a dog");
    return;
}
Dog::~Dog(void) {
    std::cout << "Dog destructor called " << std::endl;
    delete _brainPtr;
    _brainPtr = 0;
    return;
}

Dog::Dog(Dog const & toCopy): Animal(toCopy) {
    std::cout << "Dog copy constructor called" << std::endl;
    _brainPtr = new Brain(*(toCopy._brainPtr));
    *this = toCopy;
    return;
}

Dog& Dog::operator=(Dog const & toCopy) {
    if (this == &toCopy)
        return *this;
    this->_type = toCopy._type;
    delete _brainPtr;
    _brainPtr = new Brain(*(toCopy._brainPtr));
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