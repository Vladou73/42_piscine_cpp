#include "Fixed.hpp"

Fixed::Fixed(void): _val(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const & toCopy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = toCopy;
    return;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed & Fixed::operator=(Fixed const &toCopy) {
    if (this == &toCopy)
		return (*this);
    std::cout << "Copy assignment operator called" << std::endl;
    this->_val = toCopy.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const { //retourne la valeur du nombre à virgule fixe sans la convertir
    std::cout << "getRawBits member function called" << std::endl;
    return _val;
}

void Fixed::setRawBits(int const raw) { //initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
    _val = raw;
}