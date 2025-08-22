#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange btc;

        btc.setPriceDB("data.csv");
        std::ifstream infile(argv[1]);
        if (!infile)
        {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }
        btc.setInfile(infile);

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
