#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <ctime>
#include <cstring>
 
#include <iostream>
#include <string>
#include <fstream>

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &);
        BitcoinExchange const &operator=(BitcoinExchange const &);

        int     generateDatabase(void);
        double  calcExchangeRate(struct tm date, double btc);

    private:
        std::map<std::string, float>	_db;
};



#endif