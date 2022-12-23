#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void) {
	return;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << _name << ": created" << std::endl;
	return;
}

Zombie::~Zombie(void) {
	std::cout << _name << ": destroyed" << std::endl;
	return;
}

void	Zombie::name(std::string name) {
	_name = name;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
