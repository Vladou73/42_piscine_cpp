#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <ctime>
 
#include <iostream>
#include <string>
#include <fstream>

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &);
        BitcoinExchange const &operator=(BitcoinExchange const &);

        int    generateDatabase(void);

    private:
        std::map<std::string, float>	_db;
};



#endif