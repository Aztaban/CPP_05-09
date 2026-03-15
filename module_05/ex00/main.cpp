#include "Bureaucrat.hpp"
#include <iostream>

int	main(void) {
	Bureaucrat hermes = Bureaucrat("Hermes", 1);
	Bureaucrat beginner = Bureaucrat("Bob", 150);

	std::cout << "\n------- Copy constructor ------------------\n" << std::endl;
	Bureaucrat herm = Bureaucrat(hermes);
	std::cout << herm << std::endl;
	std::cout << "\n------- Copy Assignment -------------------\n" << std::endl;
	Bureaucrat copy = Bureaucrat();
	copy = hermes;
	std::cout << copy << std::endl;
	std::cout << "\n------- Grade to high construction --------\n" << std::endl;
	try {
		Bureaucrat high = Bureaucrat("High", 0);
		std::cout << high << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n------- Grade to low construction ---------\n" << std::endl;
	try {
		Bureaucrat low = Bureaucrat("Low", 151);
		std::cout << low << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n------- Decrement grade -------------------\n" << std::endl;
	std::cout << hermes << std::endl;
	hermes.decrementGrade();
	std::cout << hermes << std::endl;
	std::cout << "\n------- Increment grade -------------------\n" << std::endl;
	std::cout << hermes << std::endl;
	hermes.incrementGrade();
	std::cout << hermes << std::endl;
	std::cout << "\n------- Increment grade (too high) --------\n" << std::endl;
	try {
		hermes.incrementGrade();
		std::cout << hermes << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n------- Decrement grade (too low) ---------\n" << std::endl;
	try {
		beginner.decrementGrade();
		std::cout << beginner << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n------- Destruction -----------------------\n" << std::endl;
	
	return (0);
}