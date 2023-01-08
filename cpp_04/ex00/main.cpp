#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    {

        std::cout   << "***** Right implementation of polymorphism with virtual member functions *****"
                    << std::endl << std::endl;

        const Animal*   meta = new Animal();
        const Animal*   j = new Dog();
        const Animal*   i = new Cat();

        std::cout << "animal type is : " << meta->getType() << std::endl; //animal type
        std::cout << "animal type is : " << j->getType() << std::endl; //dog type
        std::cout << "animal type is : " << i->getType() << std::endl; //cat type

        std::cout << std::endl;

        meta->makeSound(); //animal sound
        j->makeSound(); //dog sound
        i->makeSound(); //cat sound

        std::cout << std::endl;

        delete meta;
        delete j;
        delete i;
        meta = 0;
        j = 0;
        i = 0;
    }
    {
        std::cout   << std::endl << std::endl
                    << "***** Wrong implementation of polymorphism with no virtual member functions *****"
                    << std::endl << std::endl;

        const WrongAnimal*   meta = new WrongAnimal();
        const WrongAnimal*   i = new WrongCat();

        std::cout << "animal type is : " << meta->getType() << std::endl; //animal type
        std::cout << "animal type is : " << i->getType() << std::endl; //cat type

        std::cout << std::endl;

        meta->makeSound(); //animal sound
        i->makeSound(); //cat sound

        std::cout << std::endl;

        delete meta;
        meta = 0;
        delete i;
        i = 0;


        return 0;
    }
}
