#include "Cat.hpp"

// **************** CANONICAL CLASS FUNCTIONS **************** //

Cat::Cat(void): _type("Cat") {
    std::cout << "Cat constructor called" << std::endl << std::endl;
    return;
}
Cat::~Cat(void) {
    std::cout << "Cat destructor called " << std::endl;
    return;
}

Cat::Cat(Cat const & toCopy): Animal(toCopy) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = toCopy;
    return;
}

Cat& Cat::operator=(Cat const & toCopy) {
    if (this == &toCopy)
        return *this;
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