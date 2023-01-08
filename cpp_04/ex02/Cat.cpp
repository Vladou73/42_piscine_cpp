#include "Cat.hpp"

// **************** CANONICAL CLASS FUNCTIONS **************** //

Cat::Cat(void): Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
    _brainPtr = new Brain();
}
Cat::~Cat(void) {
    std::cout << "Cat destructor called " << std::endl;
    delete _brainPtr;
    _brainPtr = 0;
}

Cat::Cat(Cat const & toCopy): Animal(toCopy), _brainPtr(0) {
    std::cout << "Cat copy constructor called" << std::endl;
    _type = toCopy._type;
    _brainPtr = new Brain(*(toCopy._brainPtr));
}

Cat& Cat::operator=(Cat const & toCopy) {
    if (this == &toCopy)
        return *this;
    _type = toCopy._type;
    delete _brainPtr;
    _brainPtr = 0;
    _brainPtr = new Brain(*(toCopy._brainPtr));
    return *this;
}

// **************** MEMBER FUNCTIONS **************** //
void    Cat::makeSound(void) const {
    std::cout << "MIAOUUUUU" << std::endl;
    return;
}
std::string  Cat::getIdea(int number) const {
    return _brainPtr->getIdea(number);
}
void    Cat::setIdea(int number, std::string idea) {
    _brainPtr->setIdea(number, idea);
}
