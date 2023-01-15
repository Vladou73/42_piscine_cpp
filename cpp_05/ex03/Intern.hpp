#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class Intern {
	public:
		Intern(void);
		~Intern(void);
		Intern(Intern const &);
		Intern& operator=(Intern const &);

		// **** other member functions **** //
		AForm	*makeForm(std::string form_name, std::string target);

	private:
		AForm	*_createShrubbery(std::string);
		AForm	*_createPresident(std::string);
		AForm	*_createRobot(std::string);
};

//définition d'un type pointeur sur fonction membre
typedef AForm *(Intern::* ptrSurFM) (std::string);

#endif
