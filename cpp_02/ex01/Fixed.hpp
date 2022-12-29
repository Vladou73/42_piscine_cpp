// https://stackoverflow.com/questions/13185751/what-is-the-difference-between-static-const-and-const
// https://stacklima.com/litteral-entier-en-c-c-prefixes-et-suffixes/
// https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html
// https://stackoverflow.com/questions/67517939/how-to-connect-the-theory-of-fixed-point-numbers-and-its-practical-implementatio

// For example, fixed<8,3> denotes a 8-bit fixed point number,
//  of which 3 right most bits are fractional. Therefore, the bit pattern:
//     0 	0 	0 	1 	0 	1 	1 	0
// represents a real number: 00010.1102
//     = 1 * 21 + 1 * 2-1 + 1 * 2-1
//     = 2 + 0.5 + 0.25
//     = 2.75

//https://stackoverflow.com/questions/141525/what-are-bitwise-shift-bit-shift-operators-and-how-do-they-work

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    public:
        Fixed(void); //constructeur par défaut
        Fixed(int const myInt);
        Fixed(float const myFloat);
        Fixed(Fixed const & toCopy); //Un constructeur de recopie
        ~Fixed(void); //destructeur
        Fixed& operator=(Fixed const & toCopy); //Une surcharge de l’opérateur d’affectation.

        int getRawBits(void) const; //retourne la valeur du nombre à virgule fixe sans la convertir
        void setRawBits(int const raw); //initialise la valeur du nombre à virgule fixe avec celle passée en paramètre

        float toFloat(void) const; //convertit la valeur en virgule xe en nombre à virgule ottante.
        int toInt(void) const; //convertit la valeur en virgule xe en nombre entier

    private:
        int _val;
        static const int _bits;
};

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream &operator<<(std::ostream & os, Fixed const & instance);

#endif