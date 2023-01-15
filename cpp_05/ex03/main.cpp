#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {

    std::cout  << std::endl << "********** Create forms **********" << std::endl << std::endl;
    Intern                  intern;
    Bureaucrat              dg("dg", 30);
    Bureaucrat              subalterne("subalterne", 137);
    AForm                   *f1 = NULL;
    AForm                   *f2 = NULL;
    AForm                   *f3 = NULL;
    AForm                   *f4 = NULL;

    f1 = intern.makeForm("shrubbery request", "target1");
    f2 = intern.makeForm("presidentary request", "target2");
    f3 = intern.makeForm("robotomy request", "target3");

    std::cout << *f1;
    std::cout << *f2;
    std::cout << *f3;

    f1->beSigned(dg);
    subalterne.executeForm(*f1);

    f4 = intern.makeForm("Piege", "target4");

    delete f1;
    delete f2;
    delete f3;

    {
    std::cout  << std::endl << "********** test of subject main **********" << std::endl << std::endl;

        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        delete rrf;
    }


    return 0;
}
