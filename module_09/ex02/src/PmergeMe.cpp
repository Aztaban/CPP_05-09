#include "PmergeMe.hpp"
#include "Colors.hpp"

#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <ctime>
#include <algorithm>

// CONSTRUCTORS AND DESTRUCTOR
PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(char **argv) {
	parseInput(argv);
}

PmergeMe::PmergeMe(const PmergeMe& copy) : _vector(copy._vector), _deque(copy._deque) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::Pair::Pair(void) : small(0), big (0), id(0) {}
PmergeMe::Pair::Pair(int small, int big, std::size_t pairId)
	: small(small), big (big), id(pairId) {}

// OPERATORS OVERLOADS

PmergeMe&	PmergeMe::operator=(const PmergeMe& copy) {
	if (this != &copy) {
		_vector = copy._vector;
		_deque = copy._deque;
	}
	return (*this);
}

// MEMBER FUNCTIONS

// PARSING
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

// SORT
void	PmergeMe::sortVector(void) {
	_vector = fordJohnsonVector(_vector);
}

void	PmergeMe::sortDeque(void) {
	_deque = fordJohnsonDeque(_deque);
}

// HELPERS
std::size_t	PmergeMe::jacobsthal(std::size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	std::size_t prev2 = 0;
	std::size_t prev1 = 1;
	std::size_t current = 0;

	for (std::size_t i = 2; i <= n; ++i)
	{
		current = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = current;
	}
	return (current);
}

std::vector<std::size_t>	PmergeMe::buildInsertionOrder(std::size_t size) {
	std::vector<std::size_t>	order;

	if (size <= 1)
		return (order);

	std::size_t	prevJacobs = 1;
	std::size_t	k = 3;

	while (true) {
		std::size_t	currJacobs = jacobsthal(k);
		if (currJacobs > size)
			currJacobs = size;
		for (std::size_t i = currJacobs; i > prevJacobs; i--)
			order.push_back(i - 1);
		if (currJacobs == size)
			break;
		prevJacobs = jacobsthal(k);
		k++;
	}
	return (order);
}

// FORD-JOHNSON (VECTOR)
std::vector<int>	PmergeMe::fordJohnsonVector(const std::vector<int>& input)
{
	bool hasStraggler;
	int straggler;
	std::vector<Pair> pairs = makePairsVector(input, hasStraggler, straggler);
	std::vector<int> mainChain;

	sortPairsVector(pairs);

	std::cout << YELLOW << "Sorted vector pairs:" << RESET << std::endl;
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		std::cout << "(" << pairs[i].small << ", " << pairs[i].big
				  << ") id=" << pairs[i].id << std::endl;
	}
	if (hasStraggler)
		std::cout << "straggler: " << straggler << std::endl;

	for (std::size_t i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].big);

	return (mainChain);
}

std::vector<PmergeMe::Pair>	PmergeMe::makePairsVector(
	const std::vector<int>& input,
	bool& hasStraggler,
	int& straggler)
{
	std::vector<Pair>	pairs;
	std::size_t	i = 0;
	std::size_t	pairId = 0;

	hasStraggler = false;
	straggler = 0;

	while (i + 1 < input.size()) {
		int	first = input[i];
		int	second = input[i + 1];

		if (first < second)
			pairs.push_back(Pair(first, second, pairId));
		else
			pairs.push_back(Pair(second, first, pairId));
		pairId++;
		i += 2;
	}

	if (i < input.size()) {
		hasStraggler = true;
		straggler = input[i];
	}
	return (pairs);
}

void	PmergeMe::sortPairsVector(std::vector<Pair>& pairs) {
	for (std::size_t i = 1; i < pairs.size(); i++) {
		Pair key = pairs[i];
		std::size_t j = i;

		while (j > 0 && pairs[j - 1].big > key.big) {
			pairs[j] = pairs[j - 1];
			j--;
		}
		pairs[j] = key;
	}
}

// FORD-JOHNSON (DEQUE)
std::deque<int>	PmergeMe::fordJohnsonDeque(const std::deque<int>& input) {
	std::deque<int> result(input);
	std::sort(result.begin(), result.end());
	return (result);
}

std::deque<PmergeMe::Pair>	PmergeMe::makePairsDeque(
	const std::deque<int>& input,
	bool& hasStraggler,
	int& straggler)
{
	std::deque<Pair>	pairs;
	std::size_t	i = 0;
	std::size_t	pairId = 0;

	hasStraggler = false;
	straggler = 0;

	while (i + 1 < input.size()) {
		int	first = input[i];
		int	second = input[i + 1];

		if (first < second)
			pairs.push_back(Pair(first, second, pairId));
		else
			pairs.push_back(Pair(second, first, pairId));
		pairId++;
		i += 2;
	}

	if (i < input.size()) {
		hasStraggler = true;
		straggler = input[i];
	}
	return (pairs);
}

// PROCESS
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

