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

bool	date_is_ok(const std::string &str, struct tm *date) {
	size_t	pos1 = 0;
	size_t	pos2 = 0;
	int		year = 0;
	int		month = 0;
	int		day = 0;

	pos1 = str.find("-");
	if (pos1 == std::string::npos) 
		return (false);
	pos2 = str.find("-", pos1 + 1);
	if (pos2 == std::string::npos) 
		return (false);
	
	year = atoi(str.substr(0, pos1).c_str());
	month = atoi(str.substr(pos1 + 1, pos2).c_str());
	day = atoi(str.substr(pos2 + 1, std::string::npos).c_str());

	if (
		year < 2009 || year > 2023
		|| month < 1 || month > 12
		|| day < 1 || day > 12
		|| (month == 2 && (day > 28))
	)
		return (false);

	date->tm_year = year - 1900;
    date->tm_mon = month - 1;
    date->tm_mday = day;
	date->tm_sec = 0;
	date->tm_min = 0;
	date->tm_hour = 12; 
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
	std::string	str_date;
	struct tm 	date;
	bool		header = true;
	while (std::getline(in_file, line)) {
		if (header == true) {
			header = false;
			continue;
		}
		memset(&date, 0, sizeof(tm));
		pos = line.find(" | ");
		if (pos == std::string::npos) {
			std::cout << "Error: bad input format missing '|' => " << line << std::endl;
			continue;
		}
		bitcoins = line.substr(pos + 3, std::string::npos);
		str_date = line.substr(0, pos);
		if (!str_has_right_format_number(bitcoins)) {
			std::cout << "Error: wrong number format => " << line << std::endl;
			continue;
		}
		if (atof(bitcoins.c_str()) < 0 || atof(bitcoins.c_str()) > 1000) {
			std::cout << "Error: number out of range => " << line << std::endl;
			continue;
		}
		if (!date_is_ok(str_date, &date)) {
			std::cout << "Error: date format => " << line << std::endl;
			continue;
		}
		exchangeRate = BE.calcExchangeRate(date, atof(bitcoins.c_str()));
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