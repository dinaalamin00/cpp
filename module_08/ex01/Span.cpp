#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}
Span::Span(const Span& other) {	*this = other; }

Span&   Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_maxSize = other._maxSize;
		this->_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}


void	Span::addNumber(int num)
{
	if (_numbers.size() >= _maxSize)
		throw	std::runtime_error("Span is Full");
	_numbers.push_back(num);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_numbers.size() >= _maxSize)
		throw	std::runtime_error("Span is Full");
	if (_numbers.size() + std::distance(begin, end) > _maxSize)
		throw	std::runtime_error("Can not add this Range");
	
	_numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
		throw	std::runtime_error("Not Enough Elements");
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int	minSpan = sorted[1] - sorted[0];
	for(unsigned int i = 1; i + 1 < sorted.size(); ++i)
	{
		if (sorted[i+1] - sorted[i] < minSpan)
			minSpan = sorted[i+1] - sorted[i];
	}
	return minSpan;
}
int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw	std::runtime_error("Not Enough Elements");
	int	min = *std::min_element(_numbers.begin(), _numbers.end());
	int	max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}
