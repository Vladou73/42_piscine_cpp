#include "easyfind.hpp"

int main(void) {
	std::vector<int> a1(5, 3);
	std::list<int> a2;

	a2.push_back(-10);
	a2.push_back(10);
	a2.push_back(890);

	int index;
	int nbr;

	nbr = 3;
	index = easyfind(a1, nbr);
	if (index < 0)
		std::cout << nbr << " : ERROR : not in array a1"<< std::endl;
	else
		std::cout << nbr  << " : FIRST OCCURENCE AT INDEX : "<< index << std::endl;

	nbr = 78;
	index = easyfind(a2, nbr);
	if (index < 0)
		std::cout << nbr << " : ERROR : not in array a2"<< std::endl;
	else
		std::cout << nbr << " : FIRST OCCURENCE AT INDEX : "<< index << std::endl;

	nbr = 890;
	index = easyfind(a2, nbr);
	if (index < 0)
		std::cout << nbr << " : ERROR : not in array a2"<< std::endl;
	else
		std::cout << nbr  << " : FIRST OCCURENCE AT INDEX : "<< index << std::endl;

	return 0;
}


