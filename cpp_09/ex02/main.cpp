//https://en.wikipedia.org/wiki/Merge-insertion_sort
//https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md

//choisir le bon conteneur : https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532251-utilisez-les-conteneurs#/id/r-7532424

// on doit pouvoir insérer à différents endroits ==> pas de vector
//fusions fréquentes : list OK, et en 2 deque ou vector ?

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	
	PmergeMe test;

	if (test.CheckStoreInput(argc, argv)) {
		std::cout << "Error : wrong input format" << std::endl;
		return 1;
	}

	test.MakePairs();


	return (0);
}
