#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void): _db() {}
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &toCopy) {
	*this = toCopy;
}
BitcoinExchange const &BitcoinExchange::operator=(BitcoinExchange const &toCopy) {
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

    return 0;

}

void dateMinusOneDay(struct tm* date)
{
    const time_t ONE_DAY = 24 * 60 * 60 ;

    // Seconds since start of epoch
    time_t date_seconds = mktime( date ) - ONE_DAY;

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    *date = *localtime(&date_seconds);
}

float BitcoinExchange::calcExchangeRate(struct tm date, double btc) {
    std::map<std::string, float>::iterator it;
    char buffer[12];

    memset(buffer, 0, sizeof(buffer));
    strftime(buffer, 12, "%Y-%m-%d", &date);
    it = _db.find(buffer);
    while (it == _db.end()) {
        memset(buffer, 0, sizeof(buffer));
        dateMinusOneDay(&date);
        strftime(buffer, 12, "%Y-%m-%d", &date);
        it = _db.find(buffer);
        if (it == _db.begin())
            return (0);
    }
    return ((float)btc * (float)(it->second));
}
