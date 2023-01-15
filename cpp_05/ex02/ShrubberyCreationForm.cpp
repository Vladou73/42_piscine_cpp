#include "ShrubberyCreationForm.hpp"

// *********** CONSTRUCTORS / DESTRUCTOR *********** //
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery Form", 145, 137), _target("no_name") {
	return;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Form", 145, 137), _target(target) {
	return;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &toCopy): AForm(toCopy) {
	*this = toCopy;
	return;
}

// *********** OVERLOADS *********** //
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &toCopy) {
	if (this == &toCopy)
		return *this;
	AForm::operator=(toCopy);
	_target = toCopy._target;

	return *this;
}

std::ostream& operator<<(std::ostream & os, ShrubberyCreationForm const &instance) {
	os	<< " Form name : " << instance.getName()
		<< " - Form signed ? : " << instance.isSigned()
		<< " - Form sign grade : " << instance.getSignGrade()
		<< " - Form execution grade : " << instance.getExecGrade()
		<< " - Form target : " << instance.getTarget() << std::endl;
	return os;
}

// *********** OTHER MEMBER FUNCTIONS *********** //
std::string ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}

void ShrubberyCreationForm::execForm() const {
	std::string filename = _target + "_shrubbery";
	std::ofstream file;

	file.open(filename.c_str());
	if (file.fail())
		std::cout << filename <<  "something went wrong with the file file" << std::endl;
	else
	{
		std::cout << filename << " file created" << std::endl;
		file <<	"             ,@@@@@@@,            "	<< std::endl;
       	file << "     ,,,.   ,@@@@@@/@@,  .oo8888o."	<< std::endl;
   		file << "  ,&%%&%&&%,@@@@@/@@@@@@,888\\88//8o"	<< std::endl;
   		file << " ,%&\\%&%&&%,@@\\@@@//@@@88\\8888//888'"	<< std::endl;
  		file << " %&&%&%&/%&&%@@\\@/ //@@@8888\\8888888'"	<< std::endl;
  		file << " %&&%/ %&%%&&@@\\V /@@' `88\\8 `//88'"	<< std::endl;
  		file << " `&%\\ ` /%&'    |.|        8\\'|8'"	<< std::endl;
  		file << "      |o|        | |         | |	"		<< std::endl;
  		file << "      |.|        | |         | |	"		<< std::endl;
		file << "  \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_"	<< std::endl;
		file.close();
	}
}
