//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7531356-associez-les-classes-et-les-pointeurs

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    public:
        //constructors, destructors
        Cat(void);                    //constructeur par défaut
        Cat(Cat const &);             //constructeur de recopie
        Cat& operator=(Cat const &);  //surcharge de l’opérateur d’affectation
        ~Cat(void);                   //destructeur

        //member functions
        void makeSound(void) const;
        std::string    getType(void) const;

    protected:
        std::string _type;
        Brain*      _brainPtr;
};

#endif