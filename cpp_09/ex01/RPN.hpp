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
        std::string       _rpn;
        std::stack<float> _stack;
};


#endif
