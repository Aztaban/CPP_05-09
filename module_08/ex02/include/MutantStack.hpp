#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

public:
	typedef typename	std::stack<T>::container_type::iterator iterator;
	typedef typename	std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack(void);
	MutantStack(const MutantStack& copy);
	MutantStack&	operator=(const MutantStack& copy);
	~MutantStack(void);

	iterator		begin(void);
	iterator		end(void);
	const_iterator	begin(void) const;
	const_iterator	end(void) const;
};

#include "MutantStack.tpp"

#endif