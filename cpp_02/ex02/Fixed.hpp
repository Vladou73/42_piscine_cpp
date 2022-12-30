//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7531066-utilisez-les-operateurs-de-comparaison
//https://stackoverflow.com/questions/31305717/member-function-with-static-linkage
//https://en.cppreference.com/w/cpp/language/static
//https://en.cppreference.com/w/cpp/language/operator_incdec

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

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;

        //The 6 comparison operators
        bool    operator==(Fixed const &) const;
        bool    operator!=(Fixed const &) const;
        bool    operator<(Fixed const &) const;
        bool    operator<=(Fixed const &) const;
        bool    operator>(Fixed const &) const;
        bool    operator>=(Fixed const &) const;

        // The 4 arithmetic operators: +, -, *, and /
        Fixed   operator+(Fixed const &);
        Fixed   operator-(Fixed const &);
        Fixed   operator*(Fixed const &);
        Fixed   operator/(Fixed const &);

        //min - max
        static  Fixed &min(Fixed &, Fixed &);
        static  const Fixed &min(Fixed const &, Fixed const &);
        static  Fixed &max(Fixed &, Fixed &);
        static  const Fixed &max(Fixed const &, Fixed const &);

        // increment/decrement
        Fixed & operator++(void); //Pre-increment
        Fixed   operator++(int); //Post-increment
        Fixed & operator--(void); //Pre-decrement
        Fixed   operator--(int); //Post-decrement

    private:
        int _val;
        static const int _bits;
};

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream &operator<<(std::ostream & os, Fixed const & instance);

#endif