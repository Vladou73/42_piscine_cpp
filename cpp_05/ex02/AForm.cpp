#include "AForm.hpp"

// *********** CONSTRUCTORS / DESTRUCTOR *********** //
AForm::AForm(void):_name("random"), _signed(false), _sign_grade(120), _exec_grade(140) {
	return;
}
AForm::AForm(std::string name, unsigned int sign_grade, unsigned int exec_grade): _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (sign_grade < MAX_GRADE || exec_grade < MAX_GRADE )
		throw AForm::GradeTooHighException();
	else if (sign_grade > MIN_GRADE || exec_grade > MIN_GRADE)
		throw AForm::GradeTooLowException();
	return;
}
AForm::~AForm(void) {
	return;
}
AForm::AForm(AForm const &toCopy): _name(toCopy._name), _signed(toCopy._signed), _sign_grade(toCopy._sign_grade), _exec_grade(toCopy._exec_grade){
	// *this = toCopy;
	return;
}

// *********** OVERLOADS *********** //
AForm& AForm::operator=(AForm const &toCopy) {
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
std::ostream& operator<<(std::ostream & os, AForm const &instance) {
	os	<< " - AForm name : " << instance.getName()
		<< " - AForm signed ? : " << instance.isSigned()
		<< " - AForm sign grade : " << instance.getSignGrade()
		<< " - AForm execution grade : " << instance.getExecGrade() << std::endl;
	return os;
}

// *********** GETTERS *********** //
std::string		AForm::getName(void) const {
	return _name;
}
bool		 	AForm::isSigned(void) const {
	return _signed;
}
unsigned int	AForm::getSignGrade(void) const {
	return _sign_grade;
}
unsigned int	AForm::getExecGrade(void) const {
	return _exec_grade;
}

// *********** OTHER MEMBER FUNCTIONS *********** //
void	AForm::beSigned(Bureaucrat const &b) {
	if (_sign_grade < b.getGrade())
		throw AForm::GradeTooHighException();
	else
		_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (_signed == false)
		throw AForm::UnsignedException();
	else if (_exec_grade < executor.getGrade())
		throw AForm::GradeTooHighException();
	else
		execForm();
}

// *********** EXCEPTIONS *********** //

const char* AForm::GradeTooHighException::what() const throw() {
	return "GradeTooHighException\n";
}
const char* AForm::GradeTooLowException::what() const throw() {
	return "GradeTooLowException\n";
}
const char* AForm::UnsignedException::what() const throw() {
	return "UnsignedException\n";
}
