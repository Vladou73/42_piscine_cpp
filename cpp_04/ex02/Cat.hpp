//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7531791-decouvrez-la-notion-de-polymorphisme
//https://en.cppreference.com/w/cpp/language/virtual

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
        Cat(Cat const &toCopy);             //constructeur de recopie
        Cat& operator=(Cat const &toCopy);  //surcharge de l’opérateur d’affectation
        ~Cat(void);                   //destructeur

        //member functions
        void        makeSound(void) const;
        std::string getIdea(int number) const;
        void        setIdea(int number, std::string idea);

    private:
        Brain* _brainPtr;
};

#endif
