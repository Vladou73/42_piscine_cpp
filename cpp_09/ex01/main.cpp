//https://fr.wikipedia.org/wiki/Notation_polonaise_inverse
//https://mathworld.wolfram.com/ReversePolishNotation.html
//choisir le bon conteneur : https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532251-utilisez-les-conteneurs#/id/r-7532424 
// notion de pile ==> stack
#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "please enter only one argument (an inverted Polish mathematical expression)" << std::endl;
		return 1;
	}

	RPN	rpn(argv[1]);
	if (rpn.checkInputFormat()) {
		std::cout << "Error" << std::endl;
		return 1;
	}

	rpn.calcRpn();

	return 0;
}
