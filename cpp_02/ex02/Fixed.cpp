#include "Fixed.hpp"

//****** CONSTRUCTORS / DESTRUCTORS ******//

Fixed::Fixed(void): _val(0) {
    return;
}
Fixed::Fixed(Fixed const & toCopy) {
    *this = toCopy;
    return;
}

Fixed::Fixed(float const myFloat): _val((int)roundf(myFloat * (1 << _bits))) {
    return;
}
Fixed::Fixed(int const myInt): _val(myInt << _bits) {
    return;
}

Fixed::~Fixed(void) {
    return;
}

//****** GETTERS / SETTERS ******//

int Fixed::getRawBits(void) const { //retourne la valeur du nombre à virgule fixe sans la convertir
    return _val;
}

void Fixed::setRawBits(int const raw) { //initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
    _val = raw;
}

//****** METHODES ET ATTRIBUTS ******//

float Fixed::toFloat(void) const {
    return (float)_val / (1 << _bits);
}

int Fixed::toInt(void) const {
    return _val >> _bits;
}

const int Fixed::_bits = 8;


//****** OPERATORS OVERLOAD ******//

Fixed & Fixed::operator=(Fixed const &toCopy) {
    if (this == &toCopy)
		return (*this);
    this->_val = toCopy._val;
    return *this;
}
std::ostream &operator<<(std::ostream & os, Fixed const & instance) {
    os << instance.toFloat();
    return os;
}

//The 6 comparison operators
bool    Fixed::operator==(Fixed const &b) const {
    return (this->_val == b._val);
}
bool    Fixed::operator!=(Fixed const &b) const {
    return (this->_val != b._val);
}
bool    Fixed::operator<(Fixed const &b) const {
    return (this->_val < b._val);
}
bool    Fixed::operator<=(Fixed const &b) const {
    return (this->_val <= b._val);
}
bool    Fixed::operator>(Fixed const &b) const {
    return (this->_val > b._val);
}
bool    Fixed::operator>=(Fixed const &b) const {
    return (this->_val >= b._val);
}

// The 4 arithmetic operators: +, -, *, and /
Fixed   Fixed::operator+(Fixed const &b) {
    return Fixed(this->toFloat() + b.toFloat());
}
Fixed   Fixed::operator-(Fixed const &b) {
    return Fixed(this->toFloat() - b.toFloat());
}
Fixed   Fixed::operator*(Fixed const &b) {
    return Fixed(this->toFloat() * b.toFloat());
}
Fixed   Fixed::operator/(Fixed const &b) {
    return Fixed(this->toFloat() / b.toFloat());
}

// The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators
Fixed & Fixed::operator++(void) { //Pre-increment
    ++this->_val;
    return *this;
}
Fixed Fixed::operator++(int) {//Post-increment
    Fixed copy(*this);
    ++*this;
    return copy;
}
Fixed & Fixed::operator--(void) { //Pre-decrement
    --this->_val;
    return *this;
}
Fixed Fixed::operator--(int) {//Post-decrement
    Fixed copy(*this);
    --*this;
    return copy;
}


// 4 MIN & MAX
Fixed & Fixed::min(Fixed &a, Fixed &b) {
    if (a._val < b._val)
        return a;
    return b;
}
Fixed & Fixed::max(Fixed &a, Fixed &b) {
    if (a._val > b._val)
        return a;
    return b;
}
const Fixed & Fixed::min(Fixed const &a, Fixed const &b) {
    if (a._val < b._val)
        return a;
    return b;
}
const Fixed & Fixed::max(Fixed const &a, Fixed const &b) {
    if (a._val > b._val)
        return a;
    return b;
}
