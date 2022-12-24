#include <iostream>
#include <string>
#include "Zombie.hpp"

int main(void) {
	int	N = 4;
	
	std::cout << "Creation d'une horde de zombies avec allocation dynamique" << std::endl;
	Zombie* zombie_horde = zombieHorde(N, "Zozo le zombie");
	
	for (int i = 0; i < N ; i++) {
		std::cout << "zombie n° " << i + 1 << std::endl;
		zombie_horde[i].announce();
	}
	
	std::cout << "delete la horde de zombies pour libérer la mémoire allouée" << std::endl;
	delete [] zombie_horde;
	
	return 0;
}
