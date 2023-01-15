#include "Intern.hpp"

// *********** CONSTRUCTORS / DESTRUCTOR *********** //
Intern::Intern(void) {
	return;
}
Intern::~Intern(void) {
	return;
}
Intern::Intern(Intern const &toCopy) {
	*this = toCopy;
	return;
}
// *********** OVERLOADS *********** //
Intern& Intern::operator=(Intern const &toCopy) {
	(void)toCopy;
	return *this;
}

// *********** OTHER MEMBER FUNCTIONS *********** //
AForm	*Intern::_createShrubbery(std::string target) {
	AForm *form = new ShrubberyCreationForm(target);
	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}
AForm	*Intern::_createPresident(std::string target) {
	AForm *form = new PresidentialPardonForm(target);
	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}
AForm	*Intern::_createRobot(std::string target) {
	AForm *form = new RobotomyRequestForm(target);
	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}

AForm	*Intern::makeForm(std::string form_name, std::string target) {
    ptrSurFM arrayPtrSurFM[] = {
        &Intern::_createShrubbery,
        &Intern::_createPresident,
        &Intern::_createRobot,
    };
    std::string names[] = {
		"shrubbery request",
		"presidentary request",
		"robotomy request"
    };
    int i = 0;
    while (i < 3) {
        if (form_name == names[i])
            return (this->*arrayPtrSurFM[i])(target);
        i++;
    }
    std::cout << "! Form name invalid !" << std::endl;
	return NULL;
}
