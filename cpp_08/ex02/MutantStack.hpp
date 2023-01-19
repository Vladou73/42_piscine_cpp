// https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532251-utilisez-les-conteneurs
//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532446-utilisez-les-iterateurs-et-les-foncteurs
//https://wiki.sei.cmu.edu/confluence/display/cplusplus/CTR53-CPP.+Use+valid+iterator+ranges

// https://en.cppreference.com/w/cpp/container/stack
//https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
# include <algorithm>
# include <stack>
#include <cmath>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>() {}
		~MutantStack() {}
		MutantStack(MutantStack const &toCopy): std::stack<T>(toCopy) {
			*this = toCopy;
		}
		MutantStack const &operator=(MutantStack const &toCopy) {
			if (this == &toCopy)
				return *this;
			this->c = toCopy.c;
			return *this;
		}

		// expose just the iterators of the underlying container. ils sont accessibles pour les classes heritant de stack car ils sont en protected
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
};

#endif

//By default, if no container
//class is specified for a particular stack class instantiation,
//the standard container deque is used.
