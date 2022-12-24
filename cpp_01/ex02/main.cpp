#include <iostream>
#include <string>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string &stringREF = str;

	std::cout << &str << std::endl; //L’adresse de la string en mémoire
	std::cout << stringPTR << std::endl; //"L’adresse stockée dans stringPTR
	std::cout << &stringREF << std::endl; //L’adresse stockée dans stringREF

	std::cout << str << std::endl; //La valeur de la string
	std::cout << *stringPTR << std::endl; //La valeur pointée par stringPTR
	std::cout << stringREF << std::endl; //La valeur pointée par stringREF

	return 0;
}