// https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7533236-creez-des-templates
// https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
	public:
		Array(void); //Construction with no parameter: Creates an empty array.
		Array(unsigned int);
		~Array(void);
		Array(Array const &);

		Array			&operator=(Array const &);
		T				&operator[](unsigned int); //Elements can be accessed through the subscript operator: [ ].
		unsigned int	size(void) const;
		class OutOfBonds : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		T				*_array;
		unsigned int	_size;
};

#endif
