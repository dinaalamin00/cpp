#ifndef PMERGME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cerrno> 
#include <climits> 
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
        template <typename Container>
        Container   generateInsertionOrder(int lastNum) const;
        void	            parseInput(int argc, char **argv);
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        PmergeMe(PmergeMe const& other);
        PmergeMe&   operator=(PmergeMe const& other);
        ~PmergeMe();
        std::vector<int>    mergeInsertionSortVector(std::vector<int> v) const;
        std::list<int>      mergeInsertionSortList(std::list<int> lst) const;
// --- Getters ----
        std::vector<int>    getVec() const ;
        std::list<int>      getLst() const ;
};

#endif 