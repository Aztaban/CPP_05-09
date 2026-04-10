#include "PmergeMe.hpp"
#include "Colors.hpp"

#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <iostream>
#include <ctime>

// CONSTRUCTORS AND DESTRUCTOR
PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(char **argv) {
	parseInput(argv);
}

PmergeMe::PmergeMe(const PmergeMe& copy) : _vector(copy._vector), _deque(copy._deque) {}

PmergeMe::~PmergeMe(void) {}

// OPERATORS OVERLOADS

PmergeMe&	PmergeMe::operator=(const PmergeMe& copy) {
	if (this != &copy) {
		_vector = copy._vector;
		_deque = copy._deque;
	}
	return (*this);
}

// MEMBER FUNCTIONS
int	PmergeMe::parsePositiveInteger(const std::string& token) const {
	std::stringstream   sstream(token);
	long	value;
	char	extra;

	if (!(sstream >> value) || (sstream >> extra))
		throw std::runtime_error("Error: invalid integer");
	if (value <= 0 || value > INT_MAX)
		throw std::runtime_error("Error: invalid integer");
	return (static_cast<int>(value));
}

bool	PmergeMe::isDuplicate(int value) const {
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); it++) {
		if (*it == value)
			return (true);
	}
	return (false);
}

void	PmergeMe::parseInput(char **argv) {
	for (int i = 1; argv[i]; i++) {
		int value = parsePositiveInteger(argv[i]);
		if (isDuplicate(value))
			throw std::runtime_error("Error: input contains duplicates");
		_vector.push_back(value);
		_deque.push_back(value);
	}
	if (_vector.empty())
		throw std::runtime_error("Error: parsing failed");
}

void	PmergeMe::sortVector(void) {
	_vector = fordJohnsonVector(_vector);
}

void	PmergeMe::sortDeque(void) {
	_deque = fordJohnsonDeque(_deque);
}

void	PmergeMe::debugProcess(void) {
	clock_t startVec;
	clock_t endVec;
	clock_t startDeq;
	clock_t endDeq;
	double  vecTime;
	double  deqTime;

	std::cout << YELLOW << "-- VECTOR FORD JOHNSON --" << RESET << std::endl;
	std::cout << "Before: " << BLUE;
	printSequence(_vector);
	std::cout << RESET << std::endl;

	startVec = clock();
	sortVector();
	endVec = clock();

	std::cout << "After: " << GREEN;
	printSequence(_vector);
	std::cout << RESET << std::endl;

	std::cout << YELLOW << "-- DEQUE FORD JOHNSON --" << RESET << std::endl;
	std::cout << "Before: " << BLUE;
	printSequence(_deque);
	std::cout << RESET << std::endl;

	startDeq = clock();
	sortDeque();
	endDeq = clock();

	std::cout << "After: " << GREEN;
	printSequence(_deque);
	std::cout << RESET << std::endl;

	vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
	deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << YELLOW << "-- RESULTS --" << RESET << std::endl;
	std::cout << "Time to process a range of " << YELLOW << _vector.size() << RESET
			  << " elements with " << YELLOW << "std::vector" << RESET << " : "
			  << GREEN << vecTime << RESET << " us" << std::endl;
	std::cout << "Time to process a range of " << YELLOW << _deque.size() << RESET
			  << " elements with " << YELLOW << "std::deque" << RESET << " : "
			  << GREEN << deqTime << RESET << " us" << std::endl;
}

// void	PmergeMe::process(void) {
//	 clock_t startVec;
//	 clock_t endVec;
//	 clock_t startDeq;
//	 clock_t endDeq;
//	 double  vecTime;
//	 double  deqTime;

//	 std::cout << "Before: ";
//	 printSequence(_vector);

//	 startVec = clock();
//	 sortVector();
//	 endVec = clock();

//	 startDeq = clock();
//	 sortDeque();
//	 endDeq = clock();

//	 vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
//	 deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

//	 std::cout << "After: ";
//	 printSequence(_vector);

//	 std::cout << "Time to process a range of " << _vector.size()
//			   << " elements with std::vector : " << vecTime << " us" << std::endl;
//	 std::cout << "Time to process a range of " << _deque.size()
//			   << " elements with std::deque : " << deqTime << " us" << std::endl;
// }

