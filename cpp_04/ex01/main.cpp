//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7531356-associez-les-classes-et-les-pointeurs
//https://stackoverflow.com/questions/184710/what-is-the-difference-between-a-deep-copy-and-a-shallow-copy

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

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
