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
#include <list>

class PmergeMe
{
    private:
        /* data */
        std::vector<int>    _vec;
        std::list<int>    _lst;
        // --------------- Helper functions -----------
        std::string         trim(const std::string &s) const;
        bool                isAllDigits(const std::string& s) const;
        std::vector<int>    insertToSortedVec(std::vector<int> sorted, int value) const;
        void                insertToSortedList(std::list<int> &sorted, int value) const;
    public:
        PmergeMe(/* args */);
        PmergeMe(PmergeMe const& other);
        PmergeMe&   operator=(PmergeMe const& other);
        ~PmergeMe();
        void	            parsePositiveUInt(const std::string& s);
        std::vector<int>    mergeInsertionSortVector(std::vector<int> v) const;
        std::list<int>      mergeInsertionSortList(std::list<int> lst) const;
// --- Getters ----
        std::vector<int>    getVec() const ;
        std::list<int>    getLst() const ;
};

#endif 