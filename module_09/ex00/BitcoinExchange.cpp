#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        this->_db = other._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::findPriceForDate(const std::string &date, double &outPrice) const
{
    std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

    if (it != _db.end() && it->first == date)
    {
        outPrice = it->second;
        return true;
    }

    if (it != _db.begin()) {
        --it;
        outPrice = it->second;
        return true;
    }

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
	int	year = atoi((date.substr(0, 4)).c_str());
    int	month = atoi((date.substr(5, 2)).c_str());
    int	day = atoi((date.substr(8, 2)).c_str());
	const int daysInMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int maxDays = daysInMonth[month];
	if (month == 2)
    {
        bool isLeap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
        if (isLeap)
			maxDays = 29;
    }
    if (month < 1 || month > 12 || day < 1 || day >  maxDays|| year < 1 || year > 2025)
		return false;
	
    return true;
}

 bool BitcoinExchange::parseDouble(const std::string &str, double &outValue) 
{ 
        std::stringstream ss(str);
        ss >> outValue;
        if (ss.fail() || !ss.eof())
            return false;
		if (outValue == -0)
			outValue = 0;
        return true;
}

void BitcoinExchange::setInfile(std::ifstream &file)
{
    std::string line;
    bool    first_line = false;
    if (!std::getline(file, line))
        throw std::runtime_error("Empty Input File!");
	while (line.empty())
	{
		if (!std::getline(file, line))
        	throw std::runtime_error("Empty Input File!");
	}
    if (line != "date | value")
        throw std::runtime_error("Input file: First Line Missing!");
    else
        first_line = true;
    (void)first_line;

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::string::size_type pos = line.find('|');
        if (pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        double value;
        if (!parseDouble(valueStr, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double price;
        if (!findPriceForDate(date, price))
        {
            std::cerr << "Error: no exchange rate available for date " << date << std::endl;
            continue;
        }

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
        throw std::runtime_error("Empty DB File!");
	while (line.empty())
	{
		if (!std::getline(infile, line))
        	throw std::runtime_error("Empty DB File!");
	}
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
