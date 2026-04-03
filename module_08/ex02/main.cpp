#include <stack>
#include <list>
#include <iostream>
#include <iomanip>
#include "MutantStack.hpp"
#include "Colors.hpp"

static void SubjectTest(void) {
	MutantStack<int>	mstack;
	std::list<int>		lst;

	mstack.push(5);
	mstack.push(17);
	lst.push_back(5);
	lst.push_back(17);
	std::cout << std::left << std::setw(7) << "Label: " << BLUE << "MStack"
			  << RESET << " | " << GREEN << "list" << RESET << std::endl;
	std::cout << std::left << std::setw(7) << "Top: " << BLUE << std::right
			  << std::setw(6) << mstack.top() << RESET << " | " << GREEN << lst.back()
			  << RESET << std::endl;
	
	mstack.pop();
	lst.pop_back();
	
	std::cout << std::left << std::setw(7) << "Size: " << BLUE << std::right
			  << std::setw(6) << mstack.size() << RESET << " | " << GREEN
			  << lst.size() << RESET << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::list<int>::iterator itl = lst.begin();
	std::list<int>::iterator itel = lst.end();

	++itl;
	--itl;
	
	while (it != ite && itl != itel)
	{
		std::cout << std::left << std::setw(7) << "Value: " <<  BLUE << std::right
				  << std::setw(6) << *it << RESET << " | " << GREEN << *itl << RESET << std::endl;
		++it;
		++itl;
	}

	std::stack<int> s(mstack);
}

static void	CopyTest(void) {
	MutantStack<int>	og;

	og.push(858);
	og.push(15);
	og.push(42);

	MutantStack<int>	copy(og);

	std::cout << std::left << std::setw(14) << "Original top: " << BLUE << og.top() << RESET << std::endl;
	std::cout << std::left << std::setw(14) << "Copy top: " << BLUE << copy.top() << RESET << std::endl;
}

static void	AssignmentTest(void) {
	MutantStack<int>	first;
	MutantStack<int>	second;

	first.push(1);
	first.push(858);
	first.push(42);

	second.push(-1);
	second.push(-42);
	second.push(-858);

	second = first;
	for (MutantStack<int>::iterator it = first.begin(); it != first.end(); it++)
		std::cout << std::left << std::setw(12) << "Og value: " << BLUE << *it << RESET << std::endl;
	for (MutantStack<int>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << std::left << std::setw(12) << "Copy value: " << BLUE << *it << RESET << std::endl;
}

static void ConstTest(void)
{
	MutantStack<int> tmp;
	tmp.push(42);
	tmp.push(84);
	tmp.push(126);
	tmp.push(168);
	tmp.push(210);

	const MutantStack<int> copy(tmp);

	for (MutantStack<int>::const_iterator it = copy.begin(); it != copy.end(); it++)
		std::cout << "Value: " << BLUE << *it << RESET << std::endl;
}


int main()
{
	std::cout << YELLOW << "\n-- MutantStack subject test --" << RESET << std::endl;
	SubjectTest();
	std::cout << YELLOW << "\n-- Copy constructor test --" << RESET << std::endl;
	CopyTest();
	std::cout << YELLOW << "\n-- Copy assignment test --" << RESET << std::endl;
	AssignmentTest();
	std::cout << YELLOW << "\n-- Const iteration test --" << RESET << std::endl;
	ConstTest();
	std::cout << std::endl;

	return 0;
}