// https://stackoverflow.com/questions/13185751/what-is-the-difference-between-static-const-and-const
// https://stacklima.com/litteral-entier-en-c-c-prefixes-et-suffixes/
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed(void); //constructeur par défaut
        Fixed(Fixed const & toCopy); //Un constructeur de recopie
        ~Fixed(void); //destructeur
        Fixed& operator=(Fixed const & toCopy); //Une surcharge de l’opérateur d’affectation.

        int getRawBits(void) const; //retourne la valeur du nombre à virgule fixe sans la convertir
        void setRawBits(int const raw); //initialise la valeur du nombre à virgule fixe avec celle passée en paramètre


    private:
        int _val;
        static const int _bits;
};

#endif