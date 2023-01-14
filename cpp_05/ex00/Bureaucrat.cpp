#include "Bureaucrat.hpp"

// *********** CONSTRUCTORS / DESTRUCTOR *********** //
Bureaucrat::Bureaucrat(void):_name("no name"), _grade(100) {
	return;
}
Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name), _grade(grade) {
	return;
}
Bureaucrat::~Bureaucrat(void) {
	return;
}
Bureaucrat::Bureaucrat(Bureaucrat const &toCopy) {
	*this = toCopy;
	return;
}

// *********** OVERLOADS *********** //
Bureaucrat& Bureaucrat::operator=(Bureaucrat const &toCopy) {
	if (this == &toCopy)
		return *this;
	// _name = toCopy._name;
	_grade = toCopy._grade;
	return *this;
}
std::ostream& operator<<(std::ostream & os, Bureaucrat const &instance) {
	os << instance.getName() << ", bureaucrat grade " << instance.getGrade() << std::endl;
	return os;
}

// *********** GETTERS *********** //
std::string		Bureaucrat::getName(void) const {
	return _name;
}
unsigned int	Bureaucrat::getGrade(void) const {
	return _grade;
}

void			Bureaucrat::incrementGrade(void) {
	_grade--;
	return;
}
void			Bureaucrat::decrementGrade(void) {
	_grade++;
}
