#include "RobotomyRequestForm.hpp"

// *********** CONSTRUCTORS / DESTRUCTOR *********** //
RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robot", 72, 45), _target("no_name") {
	return;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robot", 72, 45), _target(target) {
	return;
}
RobotomyRequestForm::~RobotomyRequestForm(void) {
	return;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &toCopy): AForm(toCopy) {
	*this = toCopy;
	return;
}

// *********** OVERLOADS *********** //
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &toCopy) {
	if (this == &toCopy)
		return *this;
	AForm::operator=(toCopy);
	_target = toCopy._target;

	return *this;
}

std::ostream& operator<<(std::ostream & os, RobotomyRequestForm const &instance) {
	os	<< " Form name : " << instance.getName()
		<< " - Form signed ? : " << instance.isSigned()
		<< " - Form sign grade : " << instance.getSignGrade()
		<< " - Form execution grade : " << instance.getExecGrade()
		<< " - Form target : " << instance.getTarget() << std::endl;
	return os;
}

// *********** OTHER MEMBER FUNCTIONS *********** //
std::string RobotomyRequestForm::getTarget(void) const {
	return (_target);
}

void RobotomyRequestForm::execForm() const {

	std::cout <<  "DRIIIIIIIIIIIIIIIIIIIIIIIL" << std::endl;
	srand(time(NULL));
	if (std::rand() % 2)
		std::cout << _target <<  " has been robotomized successfully" << std::endl;
	else
		std::cout << " ! robotomization failed !" << std::endl;
}
// Si ces algorithmes sont utilisés plusieurs fois à la suite, ils ont le défaut de toujours renvoyer la même suite de valeurs. Pour contourner ce problème, on initialise souvent ces algorithmes avec une valeur imprédictible : pourquoi pas le temps système de la machine
