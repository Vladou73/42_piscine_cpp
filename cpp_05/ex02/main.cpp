#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main(void) {

    std::cout  << std::endl << "********** Execute ShrubberyCreationForm form successfuly **********" << std::endl << std::endl;
    try {
        Bureaucrat dg("dg", 30);
        Bureaucrat subalterne("subalterne", 137);
        ShrubberyCreationForm f1("f1");

        std::cout << dg;
        std::cout << subalterne;
        std::cout << f1;

        std::cout  << std::endl << "* Signature *" << std::endl;
        dg.signForm(f1);
        std::cout << f1;

        std::cout  << std::endl << "* Execution *" << std::endl;
        subalterne.executeForm(f1);
    } catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    std::cout  << std::endl<< std::endl << "********** Execute ShrubberyCreationForm form error 1 **********" << std::endl << std::endl;
    try {
        Bureaucrat dg("dg", 30);
        Bureaucrat subalterne("subalterne", 137);
        ShrubberyCreationForm f1("f1");

        std::cout << dg;
        std::cout << subalterne;
        std::cout << f1;

        std::cout  << std::endl << "* Execution *" << std::endl;
        subalterne.executeForm(f1);

    } catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    std::cout  << std::endl << std::endl << "********** Execute ShrubberyCreationForm form error 2 **********" << std::endl << std::endl;
    try {
        Bureaucrat dg("dg", 30);
        Bureaucrat subalterne("subalterne", 138);
        ShrubberyCreationForm f1("f1");

        std::cout << dg;
        std::cout << subalterne;
        std::cout << f1;

        std::cout  << std::endl << "* Signature *" << std::endl;
        dg.signForm(f1);
        std::cout << f1;

        std::cout  << std::endl << "* Execution *" << std::endl;
        subalterne.executeForm(f1);

    } catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    std::cout  << std::endl << "********** Execute RobotomyRequestForm form successfuly **********" << std::endl << std::endl;
    try {
        Bureaucrat dg("dg", 20);
        Bureaucrat subalterne("subalterne", 44);
        RobotomyRequestForm f1("pdg");

        std::cout << dg;
        std::cout << subalterne;
        std::cout << f1;

        std::cout  << std::endl << "* Signature *" << std::endl;
        dg.signForm(f1);
        std::cout << f1;

        std::cout  << std::endl << "* Execution *" << std::endl;
        f1.execute(subalterne);

    } catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    std::cout  << std::endl << "********** Execute PresidentialPardonForm form successfuly **********" << std::endl << std::endl;
    try {
        Bureaucrat dg("dg", 3);
        Bureaucrat subalterne("subalterne", 4);
        PresidentialPardonForm f1("intern");

        std::cout << dg;
        std::cout << subalterne;
        std::cout << f1;

        std::cout  << std::endl << "* Signature *" << std::endl;
        dg.signForm(f1);
        std::cout << f1;

        std::cout  << std::endl << "* Execution *" << std::endl;
        f1.execute(subalterne);

    } catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    std::cout  << std::endl<< std::endl << "********** Execute PresidentialPardonForm form error 1 **********" << std::endl << std::endl;
    try {
        Bureaucrat dg("dg", 3);
        Bureaucrat subalterne("subalterne", 130);
        PresidentialPardonForm f1("intern");

        std::cout << dg;
        std::cout << subalterne;
        std::cout << f1;

        std::cout  << std::endl << "* Execution *" << std::endl;
        f1.execute(subalterne);

    } catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }



    return 0;
}
