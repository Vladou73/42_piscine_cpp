#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

//Right implementation of polymorphism with virtual member functions
int main(void) {
    // myBrain.setIdea(3, "I like to bath in rivers");

    // std::cout << myBrain.getIdea(0) << std::endl;
    // std::cout << myBrain.getIdea(1) << std::endl;
    // std::cout << myBrain.getIdea(2) << std::endl;
    // std::cout << myBrain.getIdea(3) << std::endl;
    
    Animal* animalHorde[10];
    // animalHorde[0] = new Dog();
    // Zombie* zombie_horde = new Zombie[N];
	for (int i = 0; i < 5; i++) {
        animalHorde[i] = new Dog();
	}

    
    // const Animal*   meta = new Animal();
    // const Animal*   j = new Dog();
    // const Animal*   i = new Cat();

    // std::cout << "animal type is : " << meta->getType() << std::endl; //animal type
    // std::cout << "animal type is : " << j->getType() << std::endl; //dog type
    // std::cout << "animal type is : " << i->getType() << std::endl; //cat type

    // std::cout << std::endl;
    
    // meta->makeSound(); //animal sound
    // j->makeSound(); //dog sound
    // i->makeSound(); //cat sound

    // std::cout << std::endl;

    // delete meta;
    // delete j;
    // delete i;

    // return 0;
}