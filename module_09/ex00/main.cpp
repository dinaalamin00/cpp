#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BitcoinExchange.hpp" // your class header

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc;

        // 1. Load the Bitcoin price database (subject CSV)
        btc.setPriceDB("data.csv");

        // 2. Open the input file given by the user
        std::ifstream infile(argv[1]);
        if (!infile) {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }

        // 3. Process the input file
        btc.setInfile(infile);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
