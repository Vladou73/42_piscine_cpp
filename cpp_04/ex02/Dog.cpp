#include "Dog.hpp"

// **************** CANONICAL CLASS FUNCTIONS **************** //

Dog::Dog(void): Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
    _brainPtr = new Brain();
}
Dog::~Dog(void) {
    std::cout << "Dog destructor called " << std::endl;
    delete _brainPtr;
    _brainPtr = 0;
}

Dog::Dog(Dog const & toCopy): Animal(toCopy), _brainPtr(0) {
    std::cout << "Dog copy constructor called" << std::endl;
    _type = toCopy._type;
    _brainPtr = new Brain(*(toCopy._brainPtr));
}

Dog& Dog::operator=(Dog const & toCopy) {
    if (this == &toCopy)
        return *this;
    _type = toCopy._type;
    delete _brainPtr;
    _brainPtr = 0;
    _brainPtr = new Brain(*(toCopy._brainPtr));
    return *this;
}

// **************** MEMBER FUNCTIONS **************** //
void    Dog::makeSound(void) const {
    std::cout << "BARK BARK BARK" << std::endl;
    return;
}
std::string  Dog::getIdea(int number) const {
    return _brainPtr->getIdea(number);
}
void    Dog::setIdea(int number, std::string idea) {
    _brainPtr->setIdea(number, idea);
}
