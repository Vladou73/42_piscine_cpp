//cours OC sur les conteneurs, iteraotirs et foncteurs : https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532446-utilisez-les-iterateurs-et-les-foncteurs
//https://cplusplus.com/reference/stl/

//choisir le bon conteneur : https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532251-utilisez-les-conteneurs#/id/r-7532424
//conteneur qui peut être utilisé : map // multimap

#include "BitcoinExchange.hpp"

int main(void) {
	BitcoinExchange test;
	test.generateDatabase();
	
	return 0;
}


// int main(void) {
// 	struct tm tm1;
// 	struct tm tm2;
	
// 	time_t	time1;
// 	time_t	time2;

// 	const char *date1 = "2010-01-25";
// 	const char *date2 = "2005-12-25";

// 	strptime(date1, "%Y-%m-%d", &tm1);
// 	strptime(date2, "%Y-%m-%d", &tm2);
	
// 	time1 = mktime(&tm1);
// 	time2 = mktime(&tm2);

// 	std::cout << tm1.tm_year << std::endl;
// 	std::cout << tm1.tm_mon << std::endl;
// 	std::cout << tm1.tm_mday << std::endl;
// 	std::cout << (time1 > time2) << std::endl;

// 	return 0;
// }


