#include "BitcoinExchange.hpp" 

BitcoinExchange::BitcoinExchange(void): _db() {
    std::cout << "instance créée" << std::endl;
}
BitcoinExchange::~BitcoinExchange(void) {
    std::cout << "destruction" << std::endl;
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &toCopy) {
	*this = toCopy;
}
BitcoinExchange const &BitcoinExchange::operator=(BitcoinExchange const &toCopy) {
	std::cout << "instance copied" << std::endl;

    if (this == &toCopy)
		return *this;
	// Using assignment operator to copy one map to the other
    _db = toCopy._db;
	return *this;
}

int    BitcoinExchange::generateDatabase(void) {

    std::string line;

	std::ifstream in_file;
    in_file.open("data.csv", std::ios::in);
    if (!in_file.is_open()) {
        std::cout << "error : could not open file data.csv. Please check permissions and file location" << std::endl;
        return 1;
    }

    while (std::getline(in_file, line)) {
        _db[line.substr(0, line.find(","))] = atof(line.substr(line.find(",") + 1, std::string::npos).c_str());
    }
    if (in_file.is_open())
		in_file.close();

    // for (std::map<std::string, float>::iterator it=_db.begin(); it!=_db.end(); ++it)
    //     std::cout << it->first << " => " << it->second << std::endl;

    return 0;

}

// int    BitcoinExchange::readArgFile(std::string filename) {

// }