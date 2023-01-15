#include "PresidentialPardonForm.hpp"

// *********** CONSTRUCTORS / DESTRUCTOR *********** //
PresidentialPardonForm::PresidentialPardonForm(void): AForm("Presidential Form", 25, 5), _target("no_name") {
	return;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Form", 25, 5), _target(target) {
	return;
}
PresidentialPardonForm::~PresidentialPardonForm(void) {
	return;
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &toCopy): AForm(toCopy) {
	*this = toCopy;
	return;
}

// *********** OVERLOADS *********** //
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &toCopy) {
	if (this == &toCopy)
		return *this;
	AForm::operator=(toCopy);
	_target = toCopy._target;

	return *this;
}

std::ostream& operator<<(std::ostream & os, PresidentialPardonForm const &instance) {
	os	<< " Form name : " << instance.getName()
		<< " - Form signed ? : " << instance.isSigned()
		<< " - Form sign grade : " << instance.getSignGrade()
		<< " - Form execution grade : " << instance.getExecGrade()
		<< " - Form target : " << instance.getTarget() << std::endl;
	return os;
}

// *********** OTHER MEMBER FUNCTIONS *********** //
std::string PresidentialPardonForm::getTarget(void) const {
	return (_target);
}

void PresidentialPardonForm::execForm() const {
	std::cout << _target <<  " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
