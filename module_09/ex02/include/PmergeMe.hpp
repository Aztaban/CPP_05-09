#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <utility>
# include <iostream>

class PmergeMe {

private:
	std::vector<int>	_vector;
	std::deque<int>		_deque;

	PmergeMe(void);

	struct Pair {
		int			small;
		int			big;
		std::size_t	id;

		Pair(void);
		Pair(int small, int big, std::size_t pairId);
	};

	// PARSING
	int		parsePositiveInteger(const std::string& token) const;
	bool	isDuplicate(int value) const;
	void	parseInput(char **argv);

	// SORT
	void	sortVector(void);
	void	sortDeque(void);

	// HELPERS
	static std::size_t	jacobsthal(std::size_t n);
	static std::vector<std::size_t>	buildInsertionOrder(std::size_t size);

	// FORD-JOHNSON (VECTOR)
	std::vector<int>	fordJohnsonVector(const std::vector<int>& input);
	std::vector<Pair>	makePairsVector(const std::vector<int>& input,
										bool& hasStraggler, int& straggler);

	void	sortPairsVector(std::vector<Pair>& pairs);
	void	insertPendVector(std::vector<Pair>& pairs, bool hasStraggler,
							int straggler, std::vector<int>& mainChain);
							

	// FORD-JOHNSON (DEQUE)
	std::deque<int>		fordJohnsonDeque(const std::deque<int>& input);
	std::deque<Pair>	makePairsDeque(const std::deque<int>& input,
										bool& hasStraggler, int& straggler);

	void	sortPairsDeque(std::deque<Pair>& pairs);
	void	insertPendDeque(std::deque<Pair>& pairs, bool hasStraggler,
							int straggler, std::deque<int>& mainChain);


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