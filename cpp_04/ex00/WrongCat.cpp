#include "WrongCat.hpp"

// **************** CANONICAL CLASS FUNCTIONS **************** //

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructor called" << std::endl << std::endl;
    return;
}
WrongCat::~WrongCat(void) {
    std::cout << "WrongCat destructor called " << std::endl;
    return;
}

WrongCat::WrongCat(WrongCat const & toCopy): WrongAnimal(toCopy) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = toCopy;
    return;
}

WrongCat& WrongCat::operator=(WrongCat const & toCopy) {
    if (this == &toCopy)
        return *this;
    this->_type = toCopy._type;
    return *this;
}

// **************** MEMBER FUNCTIONS **************** //
void    WrongCat::makeSound(void) const {
    std::cout << "MIAOUUUUU" << std::endl;
    return;
}
