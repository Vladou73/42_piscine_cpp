
#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const &);

		void execForm(void) const;

	private:
		std::string	_target;

};

std::ostream &operator<<(std::ostream & os, ShrubberyCreationForm const &instance);

#endif
