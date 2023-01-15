
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

//classe abstraite
class AForm {
	public:
		AForm(void);
		AForm(std::string, unsigned int, unsigned int);
		virtual ~AForm(void);
		AForm(AForm const &);
		AForm& operator=(AForm const &);

		// **** getters **** //
		std::string 	getName(void) const;
		bool		 	isSigned(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;

		// **** other member functions **** //
		void			beSigned(Bureaucrat const &);
		void			execute(Bureaucrat const & executor) const;
		virtual void	execForm(void) const = 0; //méthode virtuelle pure ==> la classe devient une classe abstraite, impossible de l'instancier

		// **** exception classes **** //
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class UnsignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
	private:
		std::string const	_name;
		bool				_signed;
		unsigned int const	_sign_grade;
		unsigned int const	_exec_grade;
};

std::ostream &operator<<(std::ostream & os, AForm const &instance);

#endif
