//https://en.cppreference.com/w/cpp/language/dynamic_cast
// Safely converts pointers and references to classes up, down, and sideways
// along the inheritance hierarchy.

//by far the most common use for dynamic casting is for converting
//base-class pointers into derived-class pointers.
//This process is called downcasting.

#ifndef BASE_HPP
#define BASE_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>

class Base {
    public:
		virtual ~Base(void);
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
