#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
    public:
        //constructors, destructors
        WrongAnimal(void);                       //constructeur par défaut
        WrongAnimal(std::string);                       //constructeur avec type
        WrongAnimal(WrongAnimal const &);             //constructeur de recopie
        WrongAnimal& operator=(WrongAnimal const &);  //surcharge de l’opérateur d’affectation
        virtual ~WrongAnimal(void);                      //destructeur

        //member functions
        void makeSound(void) const;
        std::string  getType() const;

    protected:
        std::string _type;
};

#endif
