#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	Base *test;
	srand(time(NULL));
    int i = std::rand()/((RAND_MAX + 1u)/3);
	if (i == 0) {
		std::cout << "type A generated" << std::endl;
		test = new A;
	} else if (i == 1) {
		test = new B;
		std::cout << "type B generated" << std::endl;
	}
	else {
		test = new C;
		std::cout << "type C generated" << std::endl;
	}
	return (test);
}


//The reason is that you can have a null pointer,
//but not a null reference - any reference has to be bound to an object.

// So when dynamic_cast for a pointer type fails it returns a null pointer and the caller can check for that,
// but when it fails for a reference type it can't return a null reference, so an exception is the only reasonable way to signal a problem.

void identify(Base* p) {
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);

	if (p == NULL)
        std::cout << "NULL PTR" << std::endl;
	else if (a)
        std::cout << "type was A" << std::endl;
	else if (b)
        std::cout << "type was B" << std::endl;
	else if (c)
        std::cout << "type was C" << std::endl;
	else
        std::cout << "type unknown" << std::endl;
}

void identify(Base& p) {
	try {
    	A &a = dynamic_cast<A&>(p);
		std::cout << "type was A" << std::endl;
		(void) a;
    }
    catch(std::exception &e) {
    }
		try {
    	B &b = dynamic_cast<B&>(p);
		std::cout << "type was B" << std::endl;
		(void) b;
    }
    catch(std::exception &e) {
    }
		try {
    	C &c = dynamic_cast<C&>(p);
		std::cout << "type was C" << std::endl;
		(void) c;
    }
    catch(std::exception &e) {
    }
}

int main(void)
{
	std::cout << "CREATION" << std::endl;
	Base *test = generate();
	Base &test2 = *test;

	std::cout << std::endl << "IDENTIFICATION" << std::endl;
	identify(test);

	std::cout << std::endl << "IDENTIFICATION 2" << std::endl;
	identify(test2);

	delete test;
	return 0;
}
