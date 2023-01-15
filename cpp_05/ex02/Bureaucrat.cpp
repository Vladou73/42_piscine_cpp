#include "Bureaucrat.hpp"

// *********** CONSTRUCTORS / DESTRUCTOR *********** //
Bureaucrat::Bureaucrat(void):_name("unnamed"), _grade(MIN_GRADE) {
	return;
}
Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name) {
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
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
	std::string *adr_name = (std::string *)&(_name); //comme _name est const, il faut passer par un ptr sur son adresse pour modifier sa valeur
	*adr_name = toCopy._name;
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

// *********** OTHER MEMBER FUNCTIONS *********** //
void	Bureaucrat::incrementGrade(void) {
	if (_grade <= MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}
void	Bureaucrat::decrementGrade(void) {
	if (_grade >= MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}
void	Bureaucrat::signForm(AForm const &f) {
	if (f.isSigned())
		std::cout << _name << " signed " << f.getName() << std::endl;
	else if (_grade <= f.getSignGrade())
		std::cout << _name << " didn't sign " << f.getName() << " because he didn't want to" << std::endl;
	else
		std::cout << _name << " couldn't sign " << f.getName() << " because his grade is too low" << std::endl;
}

// *********** EXCEPTIONS *********** //

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException\n";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException\n";
}
