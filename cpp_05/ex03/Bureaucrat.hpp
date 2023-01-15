#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

# define MIN_GRADE 150
# define MAX_GRADE 1

class AForm;

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string, unsigned int);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const &);
		Bureaucrat& operator=(Bureaucrat const &);

		// **** getters **** //
		std::string 	getName(void) const;
		unsigned int	getGrade(void) const;

		// **** other member functions **** //
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(AForm const &);
		void			executeForm(AForm const & form);

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
		unsigned int 		_grade;

};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &instance);

#endif
