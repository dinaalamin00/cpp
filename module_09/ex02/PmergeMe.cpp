#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	parseInput(argc, argv);
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
        this->_lst = other._lst;
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

void	PmergeMe::parseInput(int argc, char **argv)
{
	for(int i=1; i < argc; i++)
	{
		std::string token = trim(argv[i]);
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

		_vec.push_back((int)result);
		_lst.push_back((int)result);
	}
	
}


template <typename Container>
Container PmergeMe::generateInsertionOrder(int lastNum) const
{
    Container insertionOrder;

    if (lastNum <= 0)
		return insertionOrder;

    insertionOrder.push_back(0);
    if(lastNum > 1)
		insertionOrder.push_back(1);
	int first = 1;
    int second = 3;
    while (true)
    {
        int next = second + 2 * first;
        if (next >= lastNum)
            break;
        insertionOrder.push_back(next);
        first = second;
        second = next;
    }
	for(int j = 0; j < lastNum; ++j)
	{
        if (std::find(insertionOrder.begin(), insertionOrder.end(), j) == insertionOrder.end())
            insertionOrder.push_back(j);
    }
    return insertionOrder;
}


std::vector<int>    PmergeMe::mergeInsertionSortVector(std::vector<int> v) const
{
	// Already sorted
	if (v.size() <= 1)
	return v;
	// Step 1: Form pairs and order them
	std::vector<int>  mainChain;
	std::vector<int>  pend;
	for (unsigned int i=0; i<v.size()-1; i+=2)
	{
		int a = v[i];
        int b = v[i + 1];
        if (a > b)
			std::swap(a, b);
        mainChain.push_back(a);
        pend.push_back(b);
	}
	if (v.size() % 2 != 0)
		pend.push_back(v.back());

	mainChain = mergeInsertionSortVector(mainChain);

	std::vector<int> order = generateInsertionOrder<std::vector<int> >(pend.size());

    for (size_t i = 0; i < pend.size(); ++i)
	{
        int val = pend[ order[i] ];

		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
		mainChain.insert(pos, val);
    }
	return mainChain;
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
	if (lst.size() <= 1)
		return lst;

	std::list<int>  mainChain;
	std::list<int>  pend;

	std::list<int>::iterator	it = lst.begin();
	while (it != lst.end())
	{
		int a = *it++;
        if (it != lst.end())
		{
            int b = *it++;
            if (a > b) std::swap(a, b);
            mainChain.push_back(a);
            pend.push_back(b);
        }
		else
            pend.push_back(a);
	}

	mainChain = mergeInsertionSortList(mainChain);
    std::list<int> order = generateInsertionOrder<std::list<int> >(pend.size());
	
    for (size_t i = 0; i < order.size(); ++i)
	{
		
		std::list<int>::iterator lit = pend.begin();
		std::list<int>::iterator oit = order.begin();
		std::advance(oit, i);
		size_t	idx = *oit;
		std::advance(lit, idx);
		int val = *lit;
        std::list<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(pos, val);
    }

	return mainChain;
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