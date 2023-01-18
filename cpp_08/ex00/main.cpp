#include "whatever.hpp"

// int main(void) {
// 	double	a1 = 5.123;
// 	double 	b1 = 0.1;

// 	int		a2 = -50;
// 	int 	b2 = 18888;

// 	char	a3 = 'A';
// 	char	b3 = 'B';

// 	std::cout << std::endl << "*************** MIN ***************"<< std::endl;

// 	std::cout << "min "<< a1 << " and " << b1 << " is "<< ::min<double>(a1, b1) << std::endl;
// 	std::cout << "min "<< a2 << " and " << b2 << " is "<< ::min<int>(a2, b2) << std::endl;
// 	std::cout << "min "<< a3 << " and " << b3 << " is "<< ::min<char>(a3, b3) << std::endl;

// 	std::cout << std::endl << "*************** MAX ***************"<< std::endl;

// 	std::cout << "max "<< a1 << " and " << b1 << " is "<< ::max<double>(a1, b1) << std::endl;
// 	std::cout << "max "<< a2 << " and " << b2 << " is "<< ::max<int>(a2, b2) << std::endl;
// 	std::cout << "max "<< a3 << " and " << b3 << " is "<< ::max<char>(a3, b3) << std::endl;

// 	std::cout << std::endl << "*************** SWAP ***************"<< std::endl;

// 	std::cout << "a1="<< a1 << ", b1=" << b1 << std::endl;
// 	::swap(a1, b1);
// 	std::cout << "a1="<< a1 << ", b1=" << b1 << std::endl << std::endl;

// 	std::cout << "a2="<< a2 << ", b2=" << b2 << std::endl;
// 	::swap(a2, b2);
// 	std::cout << "a2="<< a2 << ", b2=" << b2 << std::endl << std::endl;

// 	std::cout << "a3="<< a3 << ", b3=" << b3 << std::endl;
// 	::swap(a3, b3);
// 	std::cout << "a3="<< a3 << ", b3=" << b3 << std::endl << std::endl;

// 	return 0;
// }

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}
