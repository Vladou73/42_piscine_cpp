#include "iter.hpp"

int main(void) {
	int 	a1[3] = {-50, 89, -44444};
	std::string 	a2[3] = {"un", "deux", "trois"};

	std::cout << std::endl << "*************** ARRAYS ***************"<< std::endl;
	std::cout << "array a1"<< std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << a1[i] << std::endl;
	}
	std::cout << "array a2"<< std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << a2[i] << std::endl;
	}

	std::cout << std::endl << "*************** ITER ***************"<< std::endl;
	std::cout << "array a1"<< std::endl;
	::iter(a1, 3, &print_elem);
	std::cout << "array a2"<< std::endl;
	::iter(a2, 3, &print_elem);
	return 0;
}
