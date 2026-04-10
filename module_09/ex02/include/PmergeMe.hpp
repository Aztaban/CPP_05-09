#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe {

private:
    std::vector<int>	_vector;
    std::deque<int>     _deque;

    PmergeMe(void);

    int     parsePositiveInteger(const std::string& token) const;
    bool    isDuplicate(int value) const;
    void    parseInput(char **argv);

    void    sortVector(void);
    void    sortDeque(void);

    std::vector<int>    fordJohnsonVector(const std::vector<int>& input);
    std::deque<int>     fordJohnsonDeque(const std::deque<int>& input);

    std::vector<int>    mergeInsertVectorPairs(const std::vector<int>& input);
    std::deque<int>     mergeInsertDequePairs(const std::deque<int>& input);

    std::vector<int>::iterator  vecBinSearchPos(std::vector<int>& container, int value);
    std::deque<int>::iterator   deqBinSearchPos(std::deque<int>& container, int value);

    template <typename Container>
    void    printSequence(const Container& sequence) const;

public:
    PmergeMe(char **argv);
    PmergeMe(const PmergeMe& copy);
    PmergeMe&    operator=(const PmergeMe& copy);
    ~PmergeMe(void);

    void    process(void);

};

#include "PmergeMe.tpp"

#endif