#include "easyfind.hpp"

int main(void) {
	int nbr;
	std::vector<int> a1(5, 3);
	std::vector<int>::const_iterator it1;
	std::list<int> a2;
	std::list<int>::const_iterator it2;

	a2.push_back(-10);
	a2.push_back(10);
	a2.push_back(890);

	nbr = 3;
	it1 = easyfind(a1, nbr);
	if (it1 == a1.end())
		std::cout << nbr << " : ERROR : not in array a1"<< std::endl;
	else
		std::cout << nbr  << " : FIRST OCCURENCE : "<< *it1 << std::endl;

	nbr = 78;
	it2 = easyfind(a2, nbr);
	if (it2 == a2.end())
		std::cout << nbr << " : ERROR : not in array a2"<< std::endl;
	else
		std::cout << nbr << " : FIRST OCCURENCE : "<< *it2 << std::endl;

	nbr = 890;
	it2 = easyfind(a2, nbr);
	if (it2 == a2.end())
		std::cout << nbr << " : ERROR : not in array a2"<< std::endl;
	else
		std::cout << nbr  << " : FIRST OCCURENCE : "<< *it2  << std::endl;

	return 0;
}


