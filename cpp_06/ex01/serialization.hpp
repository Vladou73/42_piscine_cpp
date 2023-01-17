// https://en.cppreference.com/w/cpp/language/reinterpret_cast

// Unlike static_cast, the reinterpret_cast expression does not compile to any CPU instructions
// (except when converting between integers and pointers).
//  It is purely a compile-time directive which instructs the compiler to treat expression as if it had the type new-type.

//https://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast

// static_casting a pointer to and from void* preserves the address. That is, in the following, a, b and c all point to the same address:

//  A pointer can be converted to any integral type large enough to hold all values of its type (e.g. to std::uintptr_t)
// example
    // // pointer to integer and back
    // std::uintptr_t v1 = reinterpret_cast<std::uintptr_t>(&i); // static_cast is an error
    // std::cout << "The value of &i is " << std::showbase << std::hex << v1 << '\n';
    // int* p1 = reinterpret_cast<int*>(v1);
    // assert(p1 == &i);


#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>
#include <iostream>
#include <string>

typedef struct s_Data {
    int     myInt;
    char    myChar;
    float   myFloat;
} Data;

#endif
