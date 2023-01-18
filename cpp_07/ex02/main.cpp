#include "Array.hpp"

int main(void) {
	try {
		Array<int> a;
		// Array<double> b(5);

		std::cout << a.size() << std::endl;
		// std::cout << b.size() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
