#include "RPN.hpp"

RPN::RPN(void): _rpn("0"), _stack() {}
RPN::RPN(std::string const &rpn): _rpn(rpn), _stack() {}
RPN::~RPN(void) {}
RPN::RPN(RPN const &toCopy) {
    *this = toCopy;
}
RPN const &RPN::operator=(RPN const &toCopy) {
    if (this == &toCopy)
        return *this;
    _rpn = toCopy._rpn;
    _stack = toCopy._stack;
    return *this;
}

int    RPN::checkInputFormat(void) {
    //throw exception if there is a pb
    int                 count_nb = 0;
    int                 count_op = 0;
    std::string         str;
    std::istringstream  istream(_rpn);
    while (getline(istream, str, ' ')) {
        if (str.length() != 1)
            return 1;
        if (std::isdigit(str[0]))
            count_nb++;
        else if (str == "*" || str == "+" || str == "-" || str == "/")
            count_op++;
        else
            return 1;
    }
    if (count_nb < 1 || count_nb != count_op + 1)
        return 1; 
    return 0;
}

int RPN::calcRpn(void) {
    std::istringstream  istream(_rpn);
    int                 tmp = 0;
    std::string         str;

    while (getline(istream, str, ' ')) {
        if (std::isdigit(str[0]))
            _stack.push(atoi(str.c_str()));
        else {
            tmp = _stack.top();
            _stack.pop();
            if (str == "+")
                tmp += _stack.top();
            else if (str == "-")
                tmp -= _stack.top();
            else if (str == "*")
                tmp *= _stack.top();
            else 
                tmp /= _stack.top();
            _stack.pop();
            _stack.push(tmp);
        }
        std::cout << _stack.top() << std::endl;
    }
    std::cout << _stack.top() << std::endl;
    return (0);
}