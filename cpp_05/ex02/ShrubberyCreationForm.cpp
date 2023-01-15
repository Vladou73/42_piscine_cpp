#include "ShrubberyCreationForm.hpp"

// *********** CONSTRUCTORS / DESTRUCTOR *********** //
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("random", 145, 137) {
	return;
}

// ShrubberyCreationForm::ShrubberyCreationForm(std::string name, unsigned int sign_grade, unsigned int exec_grade): _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
// 	if (sign_grade < MAX_GRADE || exec_grade < MAX_GRADE )
// 		throw ShrubberyCreationForm::GradeTooHighException();
// 	else if (sign_grade > MIN_GRADE || exec_grade > MIN_GRADE)
// 		throw ShrubberyCreationForm::GradeTooLowException();
// 	return;
// }

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &toCopy): AForm(toCopy) {
	return;
}

// *********** OVERLOADS *********** //
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &toCopy) {
	if (this == &toCopy)
		return *this;

	//comme les variables sont const, il faut passer par un ptr sur l'adresse pour modifier sa valeur
	std::string	*str_ptr = (std::string *)&(_name);
	*str_ptr = toCopy._name;

	unsigned int *int_ptr = (unsigned int *)&(_sign_grade);
	*int_ptr = toCopy._sign_grade;
	int_ptr = (unsigned int *)&(_exec_grade);
	*int_ptr = toCopy._exec_grade;

	_signed = toCopy._signed;
	return *this;
}
std::ostream& operator<<(std::ostream & os, ShrubberyCreationForm const &instance) {
	os	<< " - ShrubberyCreationForm name : " << instance.getName()
		<< " - ShrubberyCreationForm signed ? : " << instance.isSigned()
		<< " - ShrubberyCreationForm sign grade : " << instance.getSignGrade()
		<< " - ShrubberyCreationForm execution grade : " << instance.getExecGrade() << std::endl;
	return os;
}

// *********** GETTERS *********** //
std::string		ShrubberyCreationForm::getName(void) const {
	return _name;
}
bool		 	ShrubberyCreationForm::isSigned(void) const {
	return _signed;
}
unsigned int	ShrubberyCreationForm::getSignGrade(void) const {
	return _sign_grade;
}
unsigned int	ShrubberyCreationForm::getExecGrade(void) const {
	return _exec_grade;
}

// *********** OTHER MEMBER FUNCTIONS *********** //
void			ShrubberyCreationForm::beSigned(Bureaucrat const &b) {
	if (_sign_grade < b.getGrade())
		throw ShrubberyCreationForm::GradeTooHighException();
	else
		_signed = true;
}

// *********** EXCEPTIONS *********** //

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw() {
	return "ShrubberyCreationForm::GradeTooHighException\n";
}
const char* ShrubberyCreationForm::GradeTooLowException::what() const throw() {
	return "ShrubberyCreationForm::GradeTooLowException\n";
}
