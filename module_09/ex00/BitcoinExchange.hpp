#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>
#include <cctype>

class BitcoinExchange {
private:
    std::map<std::string, double> _db; // stores date -> price from DB

    std::string trim(std::string s);
    bool isValidDate(const std::string &date);
    bool parseDouble(const std::string &str, double &outValue);
    bool findPriceForDate(const std::string &date, double &outPrice) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void setPriceDB(std::string db_filename);
    void setInfile(std::ifstream &file);
};

#endif
