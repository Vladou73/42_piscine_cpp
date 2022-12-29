#include "Fixed.hpp"

//****** CONSTRUCTORS / DESTRUCTORS ******//

Fixed::Fixed(void): _val(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
}
Fixed::Fixed(Fixed const & toCopy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = toCopy;
    return;
}

//Calculate x = floating_input * 2^(fractional_bits) : 2^8 = 256 : bitshift de 8
//Round x to the nearest whole number (e.g. round(x))
//Store the rounded x in an integer container
Fixed::Fixed(float const myFloat): _val((int)roundf(myFloat * (1 << _bits))) {
    std::cout << "Float constructor called" << std::endl;
    return;
}
Fixed::Fixed(int const myInt): _val(myInt << _bits) {
    std::cout << "Int constructor called" << std::endl;
    return;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return;
}

//****** SURCHARGE D'OPERATEUR ******//

Fixed & Fixed::operator=(Fixed const &toCopy) {
    if (this == &toCopy)
		return (*this);
    std::cout << "Copy assignment operator called" << std::endl;
    this->_val = toCopy._val;
    return *this;
}
std::ostream &operator<<(std::ostream & os, Fixed const & instance) {
    os << instance.toFloat();
    return os;
}

//****** GETTERS / SETTERS ******//

int Fixed::getRawBits(void) const { //retourne la valeur du nombre à virgule fixe sans la convertir
    std::cout << "getRawBits member function called" << std::endl;
    return _val;
}

void Fixed::setRawBits(int const raw) { //initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
    _val = raw;
}

//****** METHODES ******//

//convertit la valeur en virgule fixe en nombre à virgule fottante.
// On divise par 256 ce qui revient a bitshift de 8 bits.
float Fixed::toFloat(void) const {
    return (float)_val / (1 << _bits);
}

//convertit la valeur en virgule fixe en nombre entier
//opération inverse de bitshifting de l'initialisation
int Fixed::toInt(void) const {
    return _val >> _bits;
}

const int Fixed::_bits = 8;