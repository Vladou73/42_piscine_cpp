#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string, unsigned int);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const &);
		Bureaucrat& operator=(Bureaucrat const &);

		//getters
		std::string 	getName(void) const;
		unsigned int	getGrade(void) const;

		void			incrementGrade(void);
		void			decrementGrade(void);

	private:
		std::string const	_name;
		unsigned int 		_grade;

};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &instance);

#endif
