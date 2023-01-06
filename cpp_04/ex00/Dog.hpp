//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7531791-decouvrez-la-notion-de-polymorphisme
//https://en.cppreference.com/w/cpp/language/virtual

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal {
    public:
        //constructors, destructors
        Dog(void);                    //constructeur par défaut
        Dog(Dog const &);             //constructeur de recopie
        Dog& operator=(Dog const &);  //surcharge de l’opérateur d’affectation
        ~Dog(void);                   //destructeur

        //member functions
        void makeSound(void) const;
        std::string    getType(void) const;

    protected:
        std::string _type;
};

#endif