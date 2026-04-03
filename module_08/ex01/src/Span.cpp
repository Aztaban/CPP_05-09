#include <algorithm>
#include "Span.hpp"

// CONSTRUCTORS AND DESTRUCTOR
Span::Span(void) : _maxSize(0), _numbers() {}
Span::Span(unsigned int N) : _maxSize(N), _numbers() {}
Span::Span(const Span& copy) : _maxSize(copy._maxSize), _numbers(copy._numbers) {}
Span::~Span(void) {}

// OPERATOR OVERLOADS
Span&	Span::operator=(const Span& copy) {
	if (this != &copy) {
		_maxSize = copy._maxSize;
		_numbers = copy._numbers;
	}
	return (*this);
}

// MEMBER FUNCTIONS
void	Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize)
		throw FullSpanException();
	_numbers.push_back(number);
}

int	Span::shortestSpan(void) const {
	if (_numbers.size() < 2)
		throw NoSpanFoundException();

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] - sorted[0];
	for (std::size_t i = 2; i < sorted.size(); i++) {
		int current = sorted[i] - sorted[i - 1];
		if (current < shortest)
			shortest = current;
	}
	return (shortest);
}

int	Span::longestSpan(void) const {
	if (_numbers.size() < 2)
		throw NoSpanFoundException();
	std::vector<int>::const_iterator	min = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator	max = std::max_element(_numbers.begin(), _numbers.end());

	return (*max - *min);
}

// EXCEPTIONS
const char* Span::FullSpanException::what() const throw() {
	return ("Container is full");
}

const char* Span::NoSpanFoundException::what() const throw() {
	return ("No span found");
}