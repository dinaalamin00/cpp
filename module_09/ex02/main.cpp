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
        PmergeMe sorter(argc, argv);

        std::cout << "Before: ";
        std::vector<int> vec = sorter.getVec();
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;

        clock_t vstart = clock();
        std::vector<int> sortedVec = sorter.mergeInsertionSortVector(sorter.getVec());
        clock_t vend = clock();

        std::cout << "Vector After: ";
        for (size_t i = 0; i < sortedVec.size(); ++i)
            std::cout << sortedVec[i] << " ";
        std::cout << std::endl;

        double vduration = double(vend - vstart) / CLOCKS_PER_SEC * 1e6; // microseconds
        std::cout << "Time to process a range of " << sortedVec.size()
                  << " elements with std::vector : "
                  << vduration << " us" << std::endl;


        // --------------------- List ----------------------------

        clock_t lstart = clock();
        std::list<int> sortedLst = sorter.mergeInsertionSortList(sorter.getLst());
        clock_t lend = clock();

        std::cout << "List After: ";
        std::list<int>::iterator it = sortedLst.begin();
        for (; it != sortedLst.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        double lduration = double(lend - lstart) / CLOCKS_PER_SEC * 1e6; // microseconds
        std::cout << "Time to process a range of " << sortedLst.size()
                  << " elements with std::list : "
                  << lduration << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

// ./PmergeMe $(shuf -i 1-100000 -n 3000)