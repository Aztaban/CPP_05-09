#include "PmergeMe.hpp"
#include "Colors.hpp"

#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <ctime>

// CONSTRUCTORS AND DESTRUCTOR
PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(char **argv) {
	_parseInput(argv);
}

PmergeMe::PmergeMe(const PmergeMe& copy) : _vector(copy._vector), _deque(copy._deque) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::Pair::Pair(void) : small(0), big (0), id(0) {}
PmergeMe::Pair::Pair(int small, int big, std::size_t pairId)
	: small(small), big (big), id(pairId) {}

PmergeMe::Node::Node(void) : value(0), pairId(0), isBig(false) {}
PmergeMe::Node::Node(int value, std::size_t pairId, bool isBig)
	: value(value), pairId(pairId), isBig(isBig) {}

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
int	PmergeMe::_parsePositiveInteger(const std::string& token) const {
	std::stringstream   sstream(token);
	long	value;
	char	extra;

	if (!(sstream >> value) || (sstream >> extra))
		throw std::runtime_error("Error: invalid integer");
	if (value <= 0 || value > INT_MAX)
		throw std::runtime_error("Error: invalid integer");
	return (static_cast<int>(value));
}

bool	PmergeMe::_isDuplicate(int value) const {
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); it++) {
		if (*it == value)
			return (true);
	}
	return (false);
}

void	PmergeMe::_parseInput(char **argv) {
	for (int i = 1; argv[i]; i++) {
		int value = _parsePositiveInteger(argv[i]);
		if (_isDuplicate(value))
			throw std::runtime_error("Error: input contains duplicates");
		_vector.push_back(value);
		_deque.push_back(value);
	}
	if (_vector.empty())
		throw std::runtime_error("Error: parsing failed");
}

// SORT
void	PmergeMe::_sortVector(void) {
	_vector = _fordJohnsonVector(_vector);
}

void	PmergeMe::_sortDeque(void) {
	_deque = _fordJohnsonDeque(_deque);
}

// HELPERS

std::size_t	PmergeMe::_jacobsthal(std::size_t n)
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

std::vector<std::size_t>	PmergeMe::_buildInsertionOrder(std::size_t size) {
	std::vector<std::size_t>	order;

	if (size <= 1)
		return (order);

	std::size_t	prevJacobs = 1;
	std::size_t	k = 3;

	while (true) {
		std::size_t	currJacobs = _jacobsthal(k);
		if (currJacobs > size)
			currJacobs = size;
		for (std::size_t i = currJacobs; i > prevJacobs; i--)
			order.push_back(i - 1);
		if (currJacobs == size)
			break;
		prevJacobs = currJacobs;
		k++;
	}
	return (order);
}

// FORD-JOHNSON (VECTOR)
std::vector<int>	PmergeMe::_fordJohnsonVector(const std::vector<int>& input)
{
	if (input.size() <= 1)
		return (input);

	bool hasStraggler;
	int straggler;
	std::vector<Pair> pairs = _makePairsVector(input, hasStraggler, straggler);
	std::vector<Node> mainChain;
	std::vector<int> result;

	_sortPairsVector(pairs);

	for (std::size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(Node(pairs[i].big, pairs[i].id, true));
	
	if (!pairs.empty())
		mainChain.insert(mainChain.begin(), Node(pairs[0].small, pairs[0].id, false));

	_insertPendVector(pairs, hasStraggler, straggler, mainChain);

	for (std::size_t i = 0; i < mainChain.size(); i++)
		result.push_back(mainChain[i].value);

	return (result);
}

std::vector<PmergeMe::Pair>	PmergeMe::_makePairsVector(
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

void	PmergeMe::_sortPairsVector(std::vector<Pair>& pairs) {
	if (pairs.size() <= 1)
		return;

	std::vector<int>	winners;
	std::vector<Pair>	sortedPairs;

	for (std::size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].big);
	
	winners = _fordJohnsonVector(winners);
	for (std::size_t i = 0; i < winners.size(); i++) {
		for (std::size_t j = 0; pairs.size(); j++) {
			if (pairs[j].big == winners[i]) {
				sortedPairs.push_back(pairs[j]);
				break;
			}
		}
	}
	pairs = sortedPairs;
}

void	PmergeMe::_insertPendVector(const std::vector<Pair>& pairs, bool hasStraggler,
							int straggler, std::vector<Node>& mainChain)
{
	std::vector<std::size_t> order = _buildInsertionOrder(pairs.size());

	for (std::size_t i = 0; i < order.size(); i++) {
		std::size_t pairIndex = order[i];
		const Pair& pair = pairs[pairIndex];

		std::size_t bigPos = _findBigPositionVector(mainChain, pair.id);
		std::size_t insertPos = _vectorBinarySearchPos(mainChain, pair.small, bigPos);

		mainChain.insert(mainChain.begin() + insertPos,
			Node(pair.small, pair.id, false));
	}

	if (hasStraggler) {
		std::size_t insertPos = _vectorBinarySearchPos(mainChain, straggler, mainChain.size());
		mainChain.insert(mainChain.begin() + insertPos, Node(straggler, static_cast<std::size_t>(-1), false));
	}
}

std::size_t	PmergeMe::_findBigPositionVector(const std::vector<Node>& chain, std::size_t pairId)
{
	for (std::size_t i = 0; i < chain.size(); ++i)
	{
		if (chain[i].pairId == pairId && chain[i].isBig)
			return i;
	}
	return chain.size();
}

std::size_t	PmergeMe::_vectorBinarySearchPos(const std::vector<Node>& chain,
									int value, std::size_t endExclusive)
{
	std::size_t left = 0;
	std::size_t right = endExclusive;

	while (left < right)
	{
		std::size_t mid = left + (right - left) / 2;
		if (chain[mid].value < value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

// FORD-JOHNSON (DEQUE)
std::deque<int>	PmergeMe::_fordJohnsonDeque(const std::deque<int>& input)
{
	if (input.size() <= 1)
		return (input);

	bool hasStraggler;
	int straggler;
	std::deque<Pair> pairs = _makePairsDeque(input, hasStraggler, straggler);
	std::deque<Node> mainChain;
	std::deque<int> result;

	_sortPairsDeque(pairs);

	for (std::size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(Node(pairs[i].big, pairs[i].id, true));
	
	if (!pairs.empty())
		mainChain.insert(mainChain.begin(), Node(pairs[0].small, pairs[0].id, false));

	_insertPendDeque(pairs, hasStraggler, straggler, mainChain);

	for (std::size_t i = 0; i < mainChain.size(); i++)
		result.push_back(mainChain[i].value);

	return (result);
}

std::deque<PmergeMe::Pair>	PmergeMe::_makePairsDeque(
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

void	PmergeMe::_sortPairsDeque(std::deque<Pair>& pairs) {
	if (pairs.size() <= 1)
		return;

	std::deque<int>	winners;
	std::deque<Pair>	sortedPairs;

	for (std::size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].big);
	
	winners = _fordJohnsonDeque(winners);
	for (std::size_t i = 0; i < winners.size(); i++) {
		for (std::size_t j = 0; pairs.size(); j++) {
			if (pairs[j].big == winners[i]) {
				sortedPairs.push_back(pairs[j]);
				break;
			}
		}
	}
	pairs = sortedPairs;
}

void	PmergeMe::_insertPendDeque(const std::deque<Pair>& pairs, bool hasStraggler,
							int straggler, std::deque<Node>& mainChain)
{
	std::vector<std::size_t> order = _buildInsertionOrder(pairs.size());

	for (std::size_t i = 0; i < order.size(); i++) {
		std::size_t pairIndex = order[i];
		const Pair& pair = pairs[pairIndex];

		std::size_t bigPos = _findBigPositionDeque(mainChain, pair.id);
		std::size_t insertPos = _dequeBinarySearchPos(mainChain, pair.small, bigPos);

		mainChain.insert(mainChain.begin() + insertPos,
			Node(pair.small, pair.id, false));
	}

	if (hasStraggler) {
		std::size_t insertPos = _dequeBinarySearchPos(mainChain, straggler, mainChain.size());
		mainChain.insert(mainChain.begin() + insertPos, Node(straggler, static_cast<std::size_t>(-1), false));
	}
}

std::size_t	PmergeMe::_findBigPositionDeque(const std::deque<Node>& chain, std::size_t pairId)
{
	for (std::size_t i = 0; i < chain.size(); ++i)
	{
		if (chain[i].pairId == pairId && chain[i].isBig)
			return i;
	}
	return chain.size();
}

std::size_t	PmergeMe::_dequeBinarySearchPos(const std::deque<Node>& chain,
									int value, std::size_t endExclusive)
{
	std::size_t left = 0;
	std::size_t right = endExclusive;

	while (left < right)
	{
		std::size_t mid = left + (right - left) / 2;
		if (chain[mid].value < value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
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
	_sortVector();
	endVec = clock();

	std::cout << "After: " << GREEN;
	printSequence(_vector);
	std::cout << RESET << std::endl;

	std::cout << YELLOW << "-- DEQUE FORD JOHNSON --" << RESET << std::endl;
	std::cout << "Before: " << BLUE;
	printSequence(_deque);
	std::cout << RESET << std::endl;

	startDeq = clock();
	_sortDeque();
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

