// https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532251-utilisez-les-conteneurs
//https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532446-utilisez-les-iterateurs-et-les-foncteurs
//https://wiki.sei.cmu.edu/confluence/display/cplusplus/CTR53-CPP.+Use+valid+iterator+ranges

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>

#include <exception>
#include <algorithm>
#include <stack>
#include <cmath>
#include <limits.h>


class RPN {
    public:
        RPN();
        RPN(std::string const &);
        ~RPN();
        RPN(RPN const &);
        RPN const &operator=(RPN const &);

        int checkInputFormat(void);
        int calcRpn(void);

    private:
        std::string     _rpn;
        std::stack<int> _stack;
};


#endif
