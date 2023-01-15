#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main(void) {

    std::cout  << std::endl << "***** Create Form with 0 sign_grade *****" << std::endl;
    try {
        ShrubberyCreationForm f1("myFile");

        std::cout << f1;
        f1.execute();

    } catch (std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }



    return 0;
}
