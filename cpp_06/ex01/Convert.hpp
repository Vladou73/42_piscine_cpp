// https://en.cppreference.com/w/cpp/language/reinterpret_cast

// Unlike static_cast, the reinterpret_cast expression does not compile to any CPU instructions
// (except when converting between integers and pointers).
//  It is purely a compile-time directive which instructs the compiler to treat expression as if it had the type new-type.

//  A pointer can be converted to any integral type large enough to hold all values of its type (e.g. to std::uintptr_t)

    // // pointer to integer and back
    // std::uintptr_t v1 = reinterpret_cast<std::uintptr_t>(&i); // static_cast is an error
    // std::cout << "The value of &i is " << std::showbase << std::hex << v1 << '\n';
    // int* p1 = reinterpret_cast<int*>(v1);
    // assert(p1 == &i);


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
