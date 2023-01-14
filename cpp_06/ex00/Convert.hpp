#ifndef CONVERT_HPP
#define CONVERT_HPP


#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <climits>
#include <cerrno>
#include <float.h>
#include <errno.h>

#define T_CHAR 0
#define T_INT 1
#define T_FLOAT 2
#define T_DOUBLE 3

class Convert {
    public:
        Convert(void);
        ~Convert(void);
        Convert(Convert const &);
        Convert& operator=(Convert const &);
        Convert(std::string);

        void    castChar(void);
        void    castInt(void);
        void    castFloat(void);
        void    castDouble(void);

        void    setType(std::string const &);
        void    convertAndPrint(void);
        void    impossibleConversion(void);

        class BadInputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        int         _type;
        std::string _input;
};

#endif