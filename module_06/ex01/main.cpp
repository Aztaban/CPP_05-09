#include "Serializer.hpp"
#include "Colors.hpp"
#include <iostream>
#include <iomanip>

int main(void) {
	Data	data;

	data.id = 1;
	data.name = "Bobo";

	Data*	originalPtr = &data;
	uintptr_t	rawPtr = Serializer::deserialize(originalPtr);
	Data*	newPtr = Serializer::serialize(rawPtr);

	std::cout << YELLOW << "\n-- Pointers print --" << RESET << std::endl;
	std::cout << std::left << std::setw(22) << "original pointer: " << BLUE << originalPtr << RESET << std::endl;
	std::cout << std::left << std::setw(22) << "deserialized pointer: " << BLUE << newPtr << RESET << std::endl;

	std::cout << YELLOW << "\n-- Equality check --" << RESET << std::endl;
	if (originalPtr == newPtr)
		std::cout << GREEN << "Pointers are equal." << RESET << std::endl;
	else
		std::cout << RED << "Pointers are not equal." << RESET << std::endl;

	std::cout << YELLOW << "\n-- Original pointer data --" << RESET << std::endl;
	std::cout << std::left << std::setw(6) << "id: " << BLUE << originalPtr->id << RESET << std::endl;
	std::cout << std::left << std::setw(6) << "name: " << BLUE << originalPtr->name << RESET << std::endl;

	std::cout << YELLOW << "\n -- Deserialized pointer data --" << RESET << std::endl;
	std::cout << std::left << std::setw(6) << "id: " << BLUE << originalPtr->id << RESET << std::endl;
	std::cout << std::left << std::setw(6) << "name: " << BLUE << originalPtr->name << RESET << std::endl << std::endl;
}