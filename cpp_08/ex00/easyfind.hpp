// https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532251-utilisez-les-conteneurs
//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532446-utilisez-les-iterateurs-et-les-foncteurs

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template<typename T>
int easyfind(const T &a, const int &nbr) {

	typename T::const_iterator it;
	int index = 0;
	for (it = a.begin(); it != a.end(); it++) {
		// std::cout << *it << std::endl;
		if (*it == nbr)
			return index;
		index++;
	}
	return -1;
}

#endif
