
#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &);
		PresidentialPardonForm& operator=(PresidentialPardonForm const &);

		std::string getTarget(void) const;
		void execForm(void) const;

	private:
		std::string	_target;

};

std::ostream &operator<<(std::ostream & os, PresidentialPardonForm const &instance);

#endif
