#include <iostream>
#include <iomanip>
#include <Array.hpp>
#include <cstdlib>
#include <ctime>
#include "Colors.hpp"

#define MAX_VAL 750

int subjectMainTest(void) {
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return (0);
}

static void testDefaultConstructor(void)
{
	Array<int> empty;
	std::cout << "empty.size() = " << BLUE << empty.size() << RESET << std::endl;

	try
	{
		empty[0] = 42;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception on empty[0]: " << e.what() << RESET << std::endl;
	}
}

static void testBasicReadWrite(void)
{
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 10;

	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << "arr[" << i << "] = " << BLUE << arr[i] << RESET << std::endl;
}

static void testIndependentCopyConstructor(void)
{
	Array<int> original(3);
	original[0] = 10;
	original[1] = 20;
	original[2] = 30;

	Array<int> copy(original);
	copy[0] = 999;

	std::cout << std::left << std::setw(14) << "original[0] = " << BLUE << original[0] << RESET << std::endl;
	std::cout << std::left << std::setw(14) << "copy[0] = " << BLUE << copy[0] << RESET << std::endl;
}

static void testAssignmentOperator(void)
{
	Array<int> a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;

	Array<int> b(2);
	b[0] = 100;
	b[1] = 200;

	b = a;
	b[1] = 999;

	std::cout << "a[1] = " << BLUE << a[1] << RESET << std::endl;
	std::cout << "b[1] = " << BLUE << b[1] << RESET << std::endl;
}

static void testConstArray(void)
{
	Array<int> tmp(3);
	tmp[0] = 7;
	tmp[1] = 8;
	tmp[2] = 9;

	const Array<int> constArr(tmp);

	for (unsigned int i = 0; i < constArr.size(); i++)
		std::cout << "constArr[" << i << "] = " << BLUE << constArr[i] << RESET << std::endl;
}

static void testStringArray(void)
{
	Array<std::string> words(3);
	words[0] = "hello";
	words[1] = "template";
	words[2] = "world";

	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << "words[" << i << "] = " << BLUE << words[i] << RESET << std::endl;
}

static void testSelfAssignment(void)
{
	Array<int> arr(3);
	arr[0] = 11;
	arr[1] = 22;
	arr[2] = 33;

	Array<int>& ref = arr;
	arr = ref;

	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << "arr[" << i << "] = " << BLUE << arr[i] << RESET << std::endl;
}

int main(int, char**)
{
	std::cout << YELLOW << "\n-- Subject Main Test --" << RESET << std::endl; 
	subjectMainTest();
	std::cout << YELLOW << "\n-- Test Default Constructor --" << RESET << std::endl;
	testDefaultConstructor();
	std::cout << YELLOW << "\n-- Test Basic Read/Write --" << RESET << std::endl;
	testBasicReadWrite();
	std::cout << YELLOW << "\n-- Test Independent Copy Constructor --" << RESET << std::endl;
	testIndependentCopyConstructor();
	std::cout << YELLOW << "\n-- Test Assignment Operator --" << RESET << std::endl;
	testAssignmentOperator();
	std::cout << YELLOW << "\n-- Test Const Array --" << RESET << std::endl;
	testConstArray();
	std::cout << YELLOW << "\n-- Test String Array --" << RESET << std::endl;
	testStringArray();
	std::cout << YELLOW << "\n-- Test Self Assignment --" << RESET << std::endl;
	testSelfAssignment();
	
	return 0;
}