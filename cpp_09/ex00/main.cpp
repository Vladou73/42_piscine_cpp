//cours OC sur les conteneurs, iteraotirs et foncteurs : https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532446-utilisez-les-iterateurs-et-les-foncteurs
//https://cplusplus.com/reference/stl/

//choisir le bon conteneur : https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532251-utilisez-les-conteneurs#/id/r-7532424
//conteneur qui peut être utilisé : map // multimap

#include "BitcoinExchange.hpp"

bool	str_has_right_format_number(const std::string &str) {
	size_t count_dots = 0;
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
		if (!std::isdigit(*it)) {
			if (*it == '.')
				count_dots++;
			else
				return (false);
		}
		if (count_dots > 1)
			return (false);
	}
	return (true);
}


int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "please use 1 argument for the program to work" << std::endl;
		return 1;
    }

	BitcoinExchange BE;
	BE.generateDatabase();


    std::string line;
    std::string filename = argv[1];
    std::ifstream in_file;

    in_file.open(filename.c_str(), std::ios::in);
    if (!in_file.is_open()) {
        std::cout << "please enter a valid existing filename as first argument" << std::endl;
        return 1;
    }

	size_t		pos;
	int			exchangeRate = 0;
	std::string	bitcoins;		
	while (std::getline(in_file, line)) {
		pos = line.find(" | ");
		if (pos == std::string::npos) {
			std::cout << "Error: bad input format missing '|' => " << line << std::endl;
			continue;
		}
		bitcoins = line.substr(pos + 3, std::string::npos);
		if (!str_has_right_format_number(bitcoins)) {
			std::cout << "Error: bad number given => " << line << std::endl;
			continue;
		}
		// exchangeRate = BE.getExchangeRate(line.substr(0, pos));
		std::cout	<< line.substr(0, pos)
					<< " => "
					<< bitcoins
					<< " = "
					<< exchangeRate
					<< std::endl;
	}

    if (in_file.is_open())
		in_file.close();
	
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


