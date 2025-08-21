#ifndef PMERGME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cerrno>   // for errno, ERANGE
#include <climits>  // for INT_MAX
#include <cstdlib>  

class PmergeMe
{
    private:
        /* data */
        std::vector<int>    _vec;
        // --------------- Helper functions -----------
        std::string         trim(const std::string &s) const;
        bool                isAllDigits(const std::string& s) const;
        std::vector<int>    insertToSorted(std::vector<int> sorted, int value) const;
    public:
        PmergeMe(/* args */);
        PmergeMe(PmergeMe const& other);
        PmergeMe&   operator=(PmergeMe const& other);
        ~PmergeMe();
        void	            parsePositiveUInt(const std::string& s);
        std::vector<int>    mergeInsertionSortVector(std::vector<int> v) const;
// --- Getters ----
        std::vector<int>    getVec() const ;
};

#endif 