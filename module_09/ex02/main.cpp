#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe <sequence of positive integers>" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe sorter;

        for (int i = 1; i < argc; ++i)
            sorter.parsePositiveUInt(argv[i]);

        std::cout << "Before: ";
        std::vector<int> vec;
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;

        clock_t start = clock();
        std::vector<int> sortedVec = sorter.mergeInsertionSortVector(sorter.getVec());
        clock_t end = clock();

        std::cout << "After: ";
        for (size_t i = 0; i < sortedVec.size(); ++i)
            std::cout << sortedVec[i] << " ";
        std::cout << std::endl;

        double duration = double(end - start) / CLOCKS_PER_SEC * 1e6; // microseconds
        std::cout << "Time to process a range of " << sortedVec.size()
                  << " elements with std::vector : "
                  << duration << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
