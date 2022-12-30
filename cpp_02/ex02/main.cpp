#include "Fixed.hpp"

// int main( void ) {
//     Fixed a;
//     Fixed const b( 10 );
//     a = Fixed( 1234.4321f );

//     std::cout << "COMPARISON OPERATORS" << std::endl;
//     std::cout << "a is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "a == b ? " << (a == b) << std::endl;
//     std::cout << "a != b ? " << (a != b) << std::endl;
//     std::cout << "a < b ? " << (a < b) << std::endl;
//     std::cout << "a <= b ? " << (a <= b) << std::endl;

//     std::cout << std::endl << std::endl;
//     a = b;
//     std::cout << "COMPARISON OPERATORS 2" << std::endl;
//     std::cout << "a is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "a == b ? " << (a == b) << std::endl;
//     std::cout << "a > b ? " << (a > b) << std::endl;
//     std::cout << "a >= b ? " << (a >= b) << std::endl;

//     a = Fixed(32.5f);
//     std::cout << std::endl << std::endl;
//     std::cout << "ARITHMETIC OPERATORS" << std::endl;
//     std::cout << "a is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "a + b = " << (a + b) << std::endl;
//     std::cout << "a / b = " << (a / b) << std::endl;
//     std::cout << "a * b = " << (a * b) << std::endl;
//     std::cout << "a - b = " << (a - b) << std::endl;

//     std::cout << std::endl << std::endl;
//     std::cout << "MIN & MAX" << std::endl;
//     std::cout << "min( a, b ) : " << Fixed::min( a, b ) << std::endl;
//     std::cout << "max( a, b ) : " << Fixed::max( a, b ) << std::endl;

//     std::cout << std::endl << std::endl;
//     std::cout << "INCREMENTATION" << std::endl;
//     std::cout << "a is " << a.getRawBits() << std::endl;
//     std::cout << "++a = " << (++a).getRawBits() << std::endl;
//     std::cout << "a = " << a.getRawBits() << std::endl;
//     std::cout << "a++ = " << (a++).getRawBits() << std::endl;
//     std::cout << "a = " << a.getRawBits() << std::endl;
//     std::cout << "--a = " << (--a).getRawBits() << std::endl;
//     std::cout << "a = " << a.getRawBits() << std::endl;
//     std::cout << "a-- = " << (a--).getRawBits() << std::endl;
//     std::cout << "a = " << a.getRawBits() << std::endl;

//     return 0;
// }

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}