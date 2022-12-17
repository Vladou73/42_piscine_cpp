#include <iostream>
#include "class.hpp"

Contact::Contact(int i, int j) : a(i), b(j) {
	std::cout << "appel du constructeur" << std::endl;

	return;
}

Contact::~Contact(void) {
	std::cout << "appel du destructeur" << std::endl;
	return;
}

void	Contact::assign(void) {

	std::cout << "member function assign called" << std::endl;

	std::cout << "this->a " << this->a << std::endl;
	std::cout << "this->b " << this->b << std::endl;


	return;
}
