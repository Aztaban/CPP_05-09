#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <utility>
# include <iostream>
# include <cstddef>

class PmergeMe {

private:
	std::vector<int>	_vector;
	std::deque<int>		_deque;
	std::size_t			_comparisons;

	struct Pair {
		int			small;
		int			big;
		std::size_t	id;

		Pair(void);
		Pair(int small, int big, std::size_t pairId);
	};

	struct Node {
		int			value;
		std::size_t	pairId;
		bool		isBig;

		Node(void);
		Node(int value, std::size_t pairId, bool isBig);
	};

	PmergeMe(void);

	// PARSING
	int		_parsePositiveInteger(const std::string& token) const;
	bool	_isDuplicate(int value) const;
	void	_parseInput(char **argv);

	// SORT
	void	_sortVector(void);
	void	_sortDeque(void);

	// HELPERS
	static std::size_t	_fordJohnsonMaxComparisons(std::size_t n);
	static std::size_t	_jacobsthal(std::size_t n);
	static std::vector<std::size_t>	_buildInsertionOrder(std::size_t size);


	// FORD-JOHNSON (VECTOR)
	std::vector<int>	_fordJohnsonVector(const std::vector<int>& input);
	std::vector<Pair>	_makePairsVector(const std::vector<int>& input,
										bool& hasStraggler, int& straggler);

	void	_sortPairsVector(std::vector<Pair>& pairs);
	void	_insertPendVector(const std::vector<Pair>& pairs, bool hasStraggler,
							int straggler, std::vector<Node>& mainChain);

	std::size_t	_findBigPositionVector(const std::vector<Node>& chain, std::size_t pairId);
	std::size_t	_vectorBinarySearchPos(const std::vector<Node>& chain, int value, std::size_t endExclusive);

	// FORD-JOHNSON (DEQUE)
	std::deque<int>		_fordJohnsonDeque(const std::deque<int>& input);
	std::deque<Pair>	_makePairsDeque(const std::deque<int>& input,
										bool& hasStraggler, int& straggler);

	void	_sortPairsDeque(std::deque<Pair>& pairs);
	void	_insertPendDeque(const std::deque<Pair>& pairs, bool hasStraggler,
							int straggler, std::deque<Node>& mainChain);

	std::size_t	_findBigPositionDeque(const std::deque<Node>& chain, std::size_t pairId);
	std::size_t	_dequeBinarySearchPos(const std::deque<Node>& chain, int value, std::size_t endExclusive);
	// PRINT
	template <typename Container>
	void	printSequence(const Container& sequence) const;

public:
	PmergeMe(char **argv);
	PmergeMe(const PmergeMe& copy);
	PmergeMe&	operator=(const PmergeMe& copy);
	~PmergeMe(void);

	//void	process(void);
	void	debugProcess(void);

};

#include "PmergeMe.tpp"

#endif