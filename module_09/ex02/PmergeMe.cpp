#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::PmergeMe(PmergeMe const& other)
{
    *this = other;
}

PmergeMe&   PmergeMe::operator=(PmergeMe const& other)
{
	if (this != &other)
    {
        this->_vec = other._vec;
        // this->_list = other._list; // if using list later
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

// ------------ helper functions -------------


std::string PmergeMe::trim(const std::string &s) const
{
    std::string::size_type start = 0;
    while (start < s.size() && std::isspace(s[start]))
        ++start;
    std::string::size_type end = s.size();
    while (end > start && std::isspace(s[end - 1]))
        --end;
    return s.substr(start, end - start);
}

bool PmergeMe::isAllDigits(const std::string& s) const
{
    if (s.empty())
        return false;
    for (unsigned int i = 0; i < s.length(); i++)
        if (!isdigit(s[i]))
            return false;
    return true;
}

void	PmergeMe::parsePositiveUInt(const std::string& s)
{
	std::string token = trim(s);
	if (token.empty())
		throw	std::runtime_error("ERROR: Empty Token!!");
	if (!isAllDigits(token))
		throw	std::runtime_error("ERROR: Not a  Number!!");
    char* endptr;
    errno = 0;
    long result;
    result = std::strtol(token.c_str(), &endptr, 10);
    if (errno == ERANGE)
        throw std::runtime_error("ERROR: Overflow!!");
    if (*endptr != '\0') 
        throw std::runtime_error("ERROR: Junk At End!!");
    if (result < 0)
        throw std::runtime_error("ERROR: Negative Number!!");
    if (result > INT_MAX)
		throw std::runtime_error("ERROR: Too Large For int!!");
	if (std::find(_vec.begin(), _vec.end(),(int)result) != _vec.end())
		throw std::runtime_error("ERROR: Duplicate!!");


	// out = (int) result;
	_vec.push_back((int)result);
	_lst.push_back((int)result);
}


std::vector<int> PmergeMe::insertToSortedVec(std::vector<int> sorted, int value) const
{
    std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
    return sorted;
}

std::vector<int>    PmergeMe::mergeInsertionSortVector(std::vector<int> v) const
{
	// Already sorted
	if (v.size() <= 1)
	return v;
	// Step 1: Form pairs and order them
	for (unsigned int i=0; i<v.size()-1; i+=2)
	{
		if (v[i] > v[i+1])
		std::swap(v[i], v[i+1]);
	}
	// Step 2: Collect smaller elements from each pair
	std::vector<int>  smalls;
	for(unsigned int i=0; i < v.size()-1; i+=2)
	smalls.push_back(v[i]);
	// Step 3: Recursively sort small elements
	smalls = mergeInsertionSortVector(smalls);
	// Step 4: Insert larger elements
	std::vector<int>  large;
	for(unsigned int i=1; i < v.size(); i+=2)
	large.push_back(v[i]);
	for (unsigned int i=0; i<large.size(); i++)
	smalls = insertToSortedVec(smalls, large[i]);
	// Step 5: Handle odd element if original vector size is odd
	if (v.size() % 2 != 0)
	smalls = insertToSortedVec(smalls, v[v.size() - 1]);
	
	return smalls;
}

void	PmergeMe::insertToSortedList(std::list<int> &sorted, int value) const
{
	std::list<int>::iterator	it = sorted.begin();
	for (; it != sorted.end(); ++it)
	{
		if (*it > value)
			break ;
	}
	sorted.insert(it, value);
}

std::list<int> PmergeMe::mergeInsertionSortList(std::list<int> lst) const
{
	// Already sorted
	if (lst.size() <= 1)
		return lst;
// Step 1: Form pairs and order them
	std::list<int>::iterator	it = lst.begin();
	while (it != lst.end())
	{
		std::list<int>::iterator	next = it;
		++next;
		if (next == lst.end())  // Odd element left alone
			break ;
		if (*it > *next)
			std::iter_swap(it, next);
		std::advance(it, 2);
	}
// Step 2: Collect smaller elements from each pair
	std::list<int>  smalls;
	it = lst.begin();
	while (it != lst.end())
	{
		std::list<int>::iterator	next = it;
		++next;
		if (next == lst.end())
			break ;
		smalls.push_back(*it);
		std::advance(it, 2);
	}
	// Step 3: Recursively sort small elements
	smalls = mergeInsertionSortList(smalls);
	// Step 4: Insert larger elements
	std::list<int>  large;
	it = lst.begin();
	// ++it;
	while (it != lst.end())
	{
		std::list<int>::iterator next = it;
    	++next;
		if (next == lst.end()) // last element not part of a pair
        	break;
		large.push_back(*next);
		std::advance(it, 2);
	}

	for (std::list<int>::iterator lit = large.begin(); lit != large.end(); ++lit)
		insertToSortedList(smalls, *lit);
// Step 5: Handle odd element if original vector size is odd
	if (lst.size() % 2 != 0)
		insertToSortedList(smalls, lst.back());

	return smalls;
}
// --- Getters -----
 std::vector<int>    PmergeMe::getVec() const 
 {
	return _vec;
 }

 std::list<int>    PmergeMe::getLst() const 
 {
	return _lst;
 }