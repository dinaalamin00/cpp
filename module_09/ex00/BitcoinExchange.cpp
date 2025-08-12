#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */)
{
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {

    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::findPriceForDate(const std::string &date, double &outPrice) const {
    // Try to find the first entry with key >= date
    std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

    // Case 1: Exact match found
    if (it != _db.end() && it->first == date) {
        outPrice = it->second;
        return true;
    }

    // Case 2: No exact match but we have earlier dates
    if (it != _db.begin()) {
        --it; // step back to closest earlier date
        outPrice = it->second;
        return true;
    }

    // Case 3: Date is earlier than the earliest DB entry
    return false;
}


std::string BitcoinExchange::trim(std::string s)
{
    std::string::size_type start = 0;
    while (start < s.size() && std::isspace(s[start]))
        ++start;

    std::string::size_type end = s.size();
    while (end > start && std::isspace(s[end - 1]))
        --end;

    return s.substr(start, end - start);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
        if (date.size() != 10 || date[4] != '-' || date[7] != '-')
            return false;
        for (size_t i = 0; i < date.size(); ++i) {
            if (i == 4 || i == 7) continue;
            if (!std::isdigit(date[i])) return false;
        }
        // Additional checks for real calendar date can be added here
        return true;
}

 bool BitcoinExchange::parseDouble(const std::string &str, double &outValue) 
{ 
        std::stringstream ss(str);
        ss >> outValue;
        if (ss.fail() || !ss.eof()) return false;
        return true;
}

void BitcoinExchange::setInfile(std::ifstream &file)
{
    std::string line;
    bool    first_line = false;
    // 1) Check first line exists
    if (!std::getline(file, line))
        throw std::runtime_error("Empty File!");
    if (line != "date | value")
        throw std::runtime_error("First Line Missing!");
    else
        first_line = true;
    (void)first_line;

    // 2) Read each subsequent line
    while (std::getline(file, line))
    {
        // std::cout << "Line: " << line << "\n";
        if (line.empty())
            continue;

        // Find separator
        std::string::size_type pos = line.find('|');
        if (pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Split into date and value parts
        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));

        // Validate date format
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Parse and validate value
        double value;
        if (!parseDouble(valueStr, value)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // Find price for this date
        double price;
        if (!findPriceForDate(date, price)) {
            std::cerr << "Error: no exchange rate available for date " << date << std::endl;
            continue;
        }

        // Compute and print result
        std::cout << date << " => " << value << " = " << (value * price) << std::endl;
    }
}


void    BitcoinExchange::setPriceDB(std::string db_filename)
{
    std::string line;
    std::string::size_type pos;
    std::string date_str;
    std::string price_str;
    std::ifstream	infile(db_filename.c_str());
	if (!infile)
        throw   std::runtime_error("Error: Cannot open DB file!");
    this->_db.clear();
     if (!std::getline(infile, line))
        throw std::runtime_error("Empty File!");
    if (line != "date,exchange_rate")
        throw std::runtime_error("First Line Missing!");
    while (std::getline(infile, line))
    {
        if (line.empty())
            continue;
        pos = line.find(',');
        if (pos == std::string::npos)
        {
            std::cerr<< "Warning: bad DB line => "  + line <<std::endl;
            continue ;
        }
        date_str = trim(line.substr(0, pos));
        price_str = trim(line.substr(pos + 1));

        if (!isValidDate(date_str))
        {
            std::cerr<< "Warning: invalid date in DB => "  + date_str <<std::endl;
            continue ;
        }
        double price;
        if (!parseDouble(price_str, price) || price < 0)
        {
            std::cerr<< "Warning: invalid price in DB => "  + price_str <<std::endl;
            continue ;
        }
        this->_db[date_str] = price; 
    }
    if (_db.empty())
        throw   std::runtime_error("Error: no valid data in database file.");
}
