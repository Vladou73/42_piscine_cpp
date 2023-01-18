// https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7533236-creez-des-templates

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void print_elem(T const &elem) {
	std::cout << "print_elem : "<< elem << std::endl;
}

template<typename T>
void iter(T *a, size_t const &len, void (*f) (T const &)) {
	for (size_t i = 0; i < len; i++) {
		f(a[i]);
	}
}

#endif
