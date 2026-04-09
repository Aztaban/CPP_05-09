#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergMe {

private:
    std::vector<int>	_vector;
    std::deque<int>     _deque;

    PmergMe(void);

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
    PmergMe(char **argv);
    PmergMe(const PmergMe& copy);
    PmergMe&    operator=(const PmergMe& copy);
    ~PmergMe(void);

    void    process(void);

};

#include "PmergeMe.tpp"

#endif