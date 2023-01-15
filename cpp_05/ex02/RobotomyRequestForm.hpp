
#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &);
		RobotomyRequestForm& operator=(RobotomyRequestForm const &);

		std::string getTarget(void) const;
		void execForm(void) const;

	private:
		std::string	_target;

};

std::ostream &operator<<(std::ostream & os, RobotomyRequestForm const &instance);

#endif
