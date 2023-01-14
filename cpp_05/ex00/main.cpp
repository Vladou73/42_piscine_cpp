#include "Bureaucrat.hpp"

int main(void) {

    std::cout  << std::endl << "***** Create bureaucrat with 0 grade *****" << std::endl;
    try {
        Bureaucrat b1("Lu", 0);
    } catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    std::cout  << std::endl << "***** Create bureaucrat with grade 164 *****" << std::endl;
    try {
        Bureaucrat b2("Do", 164);
    } catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    std::cout  << std::endl << "***** Exceed max grade *****" << std::endl;
    try {
        Bureaucrat b3("Lucie", 2);
        std::cout << b3;
        b3.incrementGrade();
        std::cout << b3;
        b3.incrementGrade();
        std::cout << b3;
    }
    catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    std::cout  << std::endl << "***** Decrement below min grade *****" << std::endl;
    try {
        Bureaucrat b4("Max", 149);
        std::cout << b4;
        b4.decrementGrade();
        std::cout << b4;
        b4.decrementGrade();
        std::cout << b4;
    }
    catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    std::cout  << std::endl << "***** Copy constructor and assignation *****" << std::endl;
    try {
        Bureaucrat b5;
        Bureaucrat b6("Chichi", 25);
        std::cout << b5;
        b5 = b6;
        std::cout << b5;
        Bureaucrat b7(b6);
        std::cout << b7;
    }
    catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

    return 0;
}
