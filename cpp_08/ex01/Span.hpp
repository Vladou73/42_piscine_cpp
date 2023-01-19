// https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532251-utilisez-les-conteneurs
//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532446-utilisez-les-iterateurs-et-les-foncteurs
//https://wiki.sei.cmu.edu/confluence/display/cplusplus/CTR53-CPP.+Use+valid+iterator+ranges

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
# include <algorithm>
# include <vector>
#include <cmath>
#include <limits.h>

class Span {
	public:
		Span(void);
		Span(unsigned int);
		~Span(void);
		Span(Span const &);
		Span const &operator=(Span const &);

		void			addNumber(int const &);
		void		 	addMultipleNumbers(int const &nbr, int const &times);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		class FullException : public std::exception {
			public:
                virtual const char* what() const throw();
		};
		class SpanException : public std::exception {
			public:
                virtual const char* what() const throw();
		};

	private:
		unsigned int		_N;
		std::vector<int>	_table;
};

#endif
