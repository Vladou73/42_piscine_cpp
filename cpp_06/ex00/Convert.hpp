// The main reason is that classic C casts make no distinction between what we call static_cast<>(), reinterpret_cast<>(), and dynamic_cast<>().
//These things are completely different.

// A static_cast<>() is usually safe. There is a valid conversion in the language, or an appropriate constructor that makes it possible.
//The only time it's a bit risky is when you cast down to an inherited class;
// you must make sure that the object is actually the descendant that you claim it is, by means external to the language (like a flag in the object).
// A dynamic_cast<>() is safe as long as the result is checked (pointer) or a possible exception is taken into account (reference).

// A reinterpret_cast<>() (or a const_cast<>()) on the other hand is always dangerous.
// You tell the compiler: "trust me: I know this doesn't look like a foo (this looks as if it isn't mutable), but it is".


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
