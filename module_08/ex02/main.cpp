#include <stack>
#include <list>
#include <iostream>
#include "MutantStack.hpp"
#include "Colors.hpp"

static void SubjectTest(void) {
	MutantStack<int>	mstack;
	std::list<int>		lst;

	mstack.push(5);
	mstack.push(17);
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Label: " << BLUE << "MutantStack" << RESET << " | " << GREEN << "list" << RESET << std::endl;
	std::cout << "Top: " << BLUE << mstack.top() << RESET << " | " << GREEN << lst.back() << RESET << std::endl;
	
	mstack.pop();
	lst.pop_back();
	
	std::cout << "Size: " << BLUE << mstack.size() << RESET << " | " << GREEN << lst.size() << RESET << std::endl;
	
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
		std::cout << "Value: " <<  BLUE << *it << RESET << " | " << GREEN << *itl << RESET << std::endl;
		++it;
		++itl;
	}

	std::stack<int> s(mstack);
}

int main()
{
	std::cout << YELLOW << "-- Subject test --" << RESET << std::endl;
	SubjectTest();
	std::cout << YELLOW << "-- Subject test --" << RESET << std::endl;
	std::cout << YELLOW << "-- Subject test --" << RESET << std::endl;
	std::cout << YELLOW << "-- Subject test --" << RESET << std::endl;
	std::cout << YELLOW << "-- Subject test --" << RESET << std::endl;
	std::cout << YELLOW << "-- Subject test --" << RESET << std::endl;
	std::cout << YELLOW << "-- Subject test --" << RESET << std::endl;
	return 0;
}