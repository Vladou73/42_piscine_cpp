#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

//classe abstraite
class Animal {
    public:
        //constructors, destructors
        Animal(void);                       //constructeur par défaut
        Animal(std::string);                   //constructeur avec un type
        Animal(Animal const &);             //constructeur de recopie
        Animal& operator=(Animal const &);  //surcharge de l’opérateur d’affectation
        virtual ~Animal(void);                      //destructeur

        //member functions
        virtual void makeSound(void) const  = 0 ; //méthode virtuelle pure ==> la classe devient une classe abstraite, impossible de l'instancier
        std::string  getType() const;

    protected:
        std::string _type;
};

#endif
