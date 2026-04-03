#include <iostream>
#include <iomanip>
#include "Span.hpp"
#include "Colors.hpp"

static void	subjectTest(void) {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << std::left << std::setw(15) << "Shortest span: " << BLUE << sp.shortestSpan() << RESET << std::endl;
	std::cout << std::left << std::setw(15) << "Longest span: " << BLUE << sp.longestSpan() << RESET << std::endl;
}

static void	emptySpanTest(void) {
	Span	sp(5);

	try {
		std::cout << std::left << std::setw(15) << "Shortest span: " << BLUE << sp.shortestSpan() << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try {
		std::cout << std::left << std::setw(15) << "Longest span: " << BLUE << sp.longestSpan() << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

static void	oneNumberTest(void) {
	Span	sp(5);

	sp.addNumber(42);

	try {
		std::cout << std::left << std::setw(15) << "Shortest span: " << BLUE << sp.shortestSpan() << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try {
		std::cout << std::left << std::setw(15) << "Longest span: " << BLUE << sp.longestSpan() << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

static void	fullSpanTest(void) {
	Span sp(3);

	try {
		for (int i = 0; i < 4; i++)
			sp.addNumber(i);
	}
	catch (std::exception& e) {
		std::cout << "addNumber exception: " << RED << e.what() << RESET << std::endl;
	}
}

static void	duplicatesTest(void) {
	Span	sp(3);

	sp.addNumber(42);
	sp.addNumber(42);
	sp.addNumber(5);

	std::cout << std::left << std::setw(15) << "Shortest span: " << BLUE << sp.shortestSpan() << RESET << std::endl;
	std::cout << std::left << std::setw(15) << "Longest span: " << BLUE << sp.longestSpan() << RESET << std::endl;
}

static void	negativeNumbersTest(void) {
	Span	sp(5);

	sp.addNumber(42);
	sp.addNumber(-42);
	sp.addNumber(420);
	sp.addNumber(-420);
	sp.addNumber(4242);

	std::cout << std::left << std::setw(15) << "Shortest span: " << BLUE << sp.shortestSpan() << RESET << std::endl;
	std::cout << std::left << std::setw(15) << "Longest span: " << BLUE << sp.longestSpan() << RESET << std::endl;
}

static void	addRangeTest(void) {
	std::vector<int>	values;
	values.push_back(42);
	values.push_back(240);
	values.push_back(24);
	values.push_back(420);

	Span sp(4);
	sp.addRange(values.begin(), values.end());

	std::cout << std::left << std::setw(15) << "Shortest span: " << BLUE << sp.shortestSpan() << RESET << std::endl;
	std::cout << std::left << std::setw(15) << "Longest span: " << BLUE << sp.longestSpan() << RESET << std::endl;
}

static void	BigSpanTest(void) {
	std::vector<int>	values;
	for (int i = 0; i < 100001; i++)
		values.push_back(i * 2);

	Span sp(100001);
	sp.addRange(values.begin(), values.end());

	std::cout << std::left << std::setw(15) << "Shortest span: " << BLUE << sp.shortestSpan() << RESET << std::endl;
	std::cout << std::left << std::setw(15) << "Longest span: " << BLUE << sp.longestSpan() << RESET << std::endl;
}

int main()
{
	std::cout << YELLOW << "\n-- Subject test --" << RESET << std::endl;
	subjectTest();
	std::cout << YELLOW << "\n-- Empty span test --" << RESET << std::endl;
	emptySpanTest();
	std::cout << YELLOW << "\n-- One number test --" << RESET << std::endl;
	oneNumberTest();
	std::cout << YELLOW << "\n-- Full span test --" << RESET << std::endl;
	fullSpanTest();
	std::cout << YELLOW << "\n-- Duplicates test --" << RESET << std::endl;
	duplicatesTest();
	std::cout << YELLOW << "\n-- Negative numbers test --" << RESET << std::endl;
	negativeNumbersTest();
	std::cout << YELLOW << "\n-- Subject test --" << RESET << std::endl;
	addRangeTest();
	std::cout << YELLOW << "\n-- 100 001 numbers test --" << RESET << std::endl;
	BigSpanTest();
	std::cout << std::endl;

	return (0);
}