#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        //constructors, destructors
        WrongCat(void);                    //constructeur par défaut
        WrongCat(WrongCat const &);             //constructeur de recopie
        WrongCat& operator=(WrongCat const &);  //surcharge de l’opérateur d’affectation
        ~WrongCat(void);                   //destructeur

        //member functions
        void makeSound(void) const;
};

#endif
