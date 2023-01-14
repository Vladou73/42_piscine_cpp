#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Please enter 1 argument" << std::endl;
		return 1;
	}
	std::string	str = argv[1];
    if (str.empty()) {
        std::cout << "This argument is empty" << std::endl;
        return 1;
	}

	try {
        Convert convert(str);
    } catch (const std::exception &e) {
        std::cout << "exception catched : " << e.what();
    }

	return 0;
}