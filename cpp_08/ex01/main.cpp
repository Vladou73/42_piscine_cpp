#include "Span.hpp"

int main(void) {

	std::cout << std::endl << "***************** FIRST TRY *****************" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "***************** SECOND TRY *****************" << std::endl;
	try {
		Span sp = Span(10000);
		sp.addMultipleNumbers(-10000, 800);
		sp.addNumber(3);
		sp.addNumber(17);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl << "***************** THIRD TRY *****************" << std::endl;
	try {
		Span sp = Span(10);
		sp.addMultipleNumbers(6, 800);
		sp.addNumber(3);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "***************** FOURTH TRY *****************" << std::endl;
	try {
		Span sp = Span(1000);
		sp.addMultipleNumbers(-10000, 1);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
