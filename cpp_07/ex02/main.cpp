#include <iostream>
#include  <cstdlib>
#include "Array.hpp"
#include "Array.tpp"

int main(void) {
    Array<int> a;
    Array<double> b(5);
    Array<std::string> c(3);

    std::cout << std::endl << "empty array a" << std::endl;
    std::cout << "size="<< a.size() << std::endl;

    std::cout << std::endl << "array b with size given" << std::endl;
    std::cout << "size="<< b.size() << std::endl;

    std::cout << std::endl << "array c with size given" << std::endl;
    std::cout << "size="<< c.size() << std::endl;

    try {
        std::cout << std::endl << "assignation to a[0] : " << std::endl;
        a[0] = 800;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
    try {
        std::cout << std::endl << "assignation to b[4] : " << std::endl;
        b[4] = 1.4568;
        std::cout << "b[4]="<< b[4] << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
    try {
        std::cout << std::endl << "assignation to c[2] : " << std::endl;
        c[2] = "myString";
        std::cout << "c[2]="<< c[2] << std::endl << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}


// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     // try
//     // {
//     //     numbers[-2] = 0;
//     // }
//     // catch(const std::exception& e)
//     // {
//     //     std::cerr << e.what() << '\n';
//     // }
//     // try
//     // {
//     //     numbers[MAX_VAL] = 0;
//     // }
//     // catch(const std::exception& e)
//     // {
//     //     std::cerr << e.what() << '\n';
//     // }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
