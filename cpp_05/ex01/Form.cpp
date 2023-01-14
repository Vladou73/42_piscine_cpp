#include "Form.hpp"

// *********** CONSTRUCTORS / DESTRUCTOR *********** //
Form::Form(void):_name("random"), _signed(false), _sign_grade(120), _exec_grade(140) {
	return;
}
Form::Form(std::string name, unsigned int sign_grade, unsigned int exec_grade): _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (sign_grade < MAX_GRADE || exec_grade < MAX_GRADE )
		throw Form::GradeTooHighException();
	else if (sign_grade > MIN_GRADE || exec_grade > MIN_GRADE)
		throw Form::GradeTooLowException();
	return;
}
Form::~Form(void) {
	return;
}
Form::Form(Form const &toCopy): _name(toCopy._name), _signed(toCopy._signed), _sign_grade(toCopy._sign_grade), _exec_grade(toCopy._exec_grade){
	// *this = toCopy;
	return;
}

// *********** OVERLOADS *********** //
Form& Form::operator=(Form const &toCopy) {
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
std::ostream& operator<<(std::ostream & os, Form const &instance) {
	os	<< " - Form name : " << instance.getName()
		<< " - Form signed ? : " << instance.isSigned()
		<< " - Form sign grade : " << instance.getSignGrade()
		<< " - Form execution grade : " << instance.getExecGrade() << std::endl;
	return os;
}

// *********** GETTERS *********** //
std::string		Form::getName(void) const {
	return _name;
}
bool		 	Form::isSigned(void) const {
	return _signed;
}
unsigned int	Form::getSignGrade(void) const {
	return _sign_grade;
}
unsigned int	Form::getExecGrade(void) const {
	return _exec_grade;
}

// *********** OTHER MEMBER FUNCTIONS *********** //
void			Form::beSigned(Bureaucrat const &b) {
	if (_sign_grade < b.getGrade())
		throw Form::GradeTooHighException();
	else
		_signed = true;
}

// *********** EXCEPTIONS *********** //

const char* Form::GradeTooHighException::what() const throw() {
	return "Form::GradeTooHighException\n";
}
const char* Form::GradeTooLowException::what() const throw() {
	return "Form::GradeTooLowException\n";
}
