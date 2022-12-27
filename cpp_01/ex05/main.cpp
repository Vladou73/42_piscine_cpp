// http://sitesimons.free.fr/C++2/A9.pdf
// https://stackoverflow.com/questions/43205893/array-of-pointers-on-member-functions-of-current-class
#include "Harl.hpp"

int main(void) {
    Harl first;
    
    first.complain("DEBUG");

    first.complain("INFO");

    first.complain("ERROR");

    first.complain("GREAT ERROR");

    return 0;
}