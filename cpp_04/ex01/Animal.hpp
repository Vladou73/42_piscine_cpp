//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7531791-decouvrez-la-notion-de-polymorphisme
//https://en.cppreference.com/w/cpp/language/virtual

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    public:
        //constructors, destructors
        Animal(void);                       //constructeur par défaut
        Animal(Animal const &);             //constructeur de recopie
        Animal& operator=(Animal const &);  //surcharge de l’opérateur d’affectation
        virtual ~Animal(void);                      //destructeur

        //member functions
        virtual void makeSound(void) const;
        virtual std::string  getType() const;

    protected:
        std::string _type;
};

#endif