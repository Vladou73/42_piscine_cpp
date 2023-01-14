
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(void);
		Form(std::string, unsigned int, unsigned int);
		~Form(void);
		Form(Form const &);
		Form& operator=(Form const &);

		// **** getters **** //
		std::string 	getName(void) const;
		bool		 	isSigned(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;

		// **** other member functions **** //
		void			beSigned(Bureaucrat const &);

		// **** exception classes **** //
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
		unsigned int const	_sign_grade;
		unsigned int const	_exec_grade;
};

std::ostream &operator<<(std::ostream & os, Form const &instance);

#endif
