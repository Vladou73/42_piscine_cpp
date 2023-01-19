// https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532251-utilisez-les-conteneurs
//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532446-utilisez-les-iterateurs-et-les-foncteurs

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template<typename T>
typename T::const_iterator easyfind(const T &a, const int &nbr) {
	return find(a.begin(), a.end(), nbr);
}

#endif
