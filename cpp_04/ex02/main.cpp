//https://en.cppreference.com/w/cpp/language/abstract_class
//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7710051-mettez-en-oeuvre-le-polymorphisme#/id/r-7710131

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

// int main(void) {
//     {
//         std::cout   << "***** creating instances of classes which are derived from the abstract class Animal *****"
//                     << std::endl << std::endl;

//         // const Animal*   meta = new Animal();
//         const Animal*   j = new Dog();
//         const Animal*   i = new Cat();

//         // std::cout << "animal type is : " << meta->getType() << std::endl; //animal type
//         std::cout << "animal type is : " << j->getType() << std::endl; //dog type
//         std::cout << "animal type is : " << i->getType() << std::endl; //cat type

//         std::cout << std::endl;

//         // meta->makeSound(); //animal sound
//         j->makeSound(); //dog sound
//         i->makeSound(); //cat sound

//         std::cout << std::endl;

//         // delete meta;
//         delete j;
//         delete i;
//         // meta = 0;
//         j = 0;
//         i = 0;
//     }
// }

int main(void) {
    {
        std::cout   << std::endl << std::endl
            << "********** TEST STANDARD CONSTRUCTOR/DESTRUCTORS **********"
            << std::endl << std::endl;

        //******* create animals *******
        Animal* animalHorde[10];
        for (int i = 0; i < 10; i++) {
            if (i < 5)
                animalHorde[i] = new Dog();
            else
                animalHorde[i] = new Cat();
        }

        //******* animals make sound *******
        for (int i = 0; i < 10; i++) {
            animalHorde[i]->makeSound();
        }

        std::cout << std::endl;

        //******* delete animals *******
        for (int i = 0; i < 10; i++) {
            delete animalHorde[i];
        }
    }
    {
        std::cout   << std::endl << std::endl
                    << "********** TEST COPY CONSTRUCTOR **********"
                    << std::endl << std::endl;

		Cat *cat = new Cat();
		Cat	*copyCat = new Cat(*cat);
		std::cout << std::endl;

        std::cout << "standard idea 50 is : " << cat->getIdea(50) << std::endl;

        cat->setIdea(50, "my own idea");
        copyCat->setIdea(50, "copyCat idea");

        std::cout << "cat idea 50 is : " << cat->getIdea(50) << std::endl;
        std::cout << "copyCat idea 50 is : " << copyCat->getIdea(50) << std::endl;

        std::cout << std::endl;

		delete cat;
		cat = 0;
		delete copyCat;
		copyCat = 0;
    }
    return 0;
}
