#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void) {

    std::cout  << std::endl << "***** Create Form with 0 sign_grade *****" << std::endl;
    try {
        Form f1("f1", 0, 10);
    } catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    std::cout  << std::endl << "***** Create Form with 164 exec_grade *****" << std::endl;
    try {
        Form f2("f2", 50, 164);
    } catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    std::cout  << std::endl << "***** Bureaucrat signing grade successfuly *****" << std::endl;
    try {
        Bureaucrat b1("Lu", 45);
        Form f3("f3", 50, 60);

        std::cout << b1;
        std::cout << f3;
        b1.signForm(f3);
    }
    catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }
    std::cout  << std::endl << "***** Bureaucrat couldn't sign grade *****" << std::endl;
    try {
        Bureaucrat b2("Do", 45);
        Form f4("f4", 35, 60);
        std::cout << b2;
        std::cout << f4;
        b2.signForm(f4);
    }
    catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    std::cout  << std::endl << "***** Copy constructor *****" << std::endl;
    try {
        Form f5("f5", 149, 150);
        std::cout << f5;
        Form f6(f5);
        std::cout << f6;
    }
    catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    return 0;
}
