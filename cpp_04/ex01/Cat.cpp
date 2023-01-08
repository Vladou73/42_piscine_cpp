#include "Cat.hpp"

// **************** CANONICAL CLASS FUNCTIONS **************** //

Cat::Cat(void): _type("Cat"), _brainPtr(0) {
    std::cout << "Cat constructor called" << std::endl << std::endl;
    _brainPtr = new Brain();
    _brainPtr->setIdea(0, "I am a cat");
    return;
}
Cat::~Cat(void) {
    std::cout << "Cat destructor called " << std::endl;
    delete _brainPtr;
    _brainPtr = 0;
    return;
}

Cat::Cat(Cat const & toCopy): Animal(toCopy) {
    std::cout << "Cat copy constructor called" << std::endl;
    _brainPtr = new Brain(*(toCopy._brainPtr));
    this->_type = toCopy._type;
    return;
}

Cat& Cat::operator=(Cat const & toCopy) {
    if (this == &toCopy)
        return *this;
    delete _brainPtr;
    _brainPtr = new Brain(*(toCopy._brainPtr));
    this->_type = toCopy._type;
    return *this;    
}

// **************** MEMBER FUNCTIONS **************** //
void    Cat::makeSound(void) const {
    std::cout << "MIAOUUUUU" << std::endl;
    return;
}
std::string    Cat::getType(void) const {
    return this->_type;
}