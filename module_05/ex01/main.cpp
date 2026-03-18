#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void) {
	std::cout << "\n------- Construction ----------------------\n" << std::endl;
	Bureaucrat	hermes = Bureaucrat("Hermes", 1);
	Bureaucrat	beginner = Bureaucrat("Bob", 150);
	Form		form = Form("Driver license", 50, 50);

	std::cout << "\n------- Copy constructor ------------------\n" << std::endl;
	Form	test = Form(form);
	std::cout << test << std::endl;

	std::cout << "\n------- Copy Assignment -------------------\n" << std::endl;
	Form copy = Form();
	copy = form;
	std::cout << copy << std::endl;

	std::cout << "\n------- Grade to high construction --------\n" << std::endl;
	try {
		Form high = Form("High", 0, 0);
		std::cout << high << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n------- Grade to low construction ---------\n" << std::endl;
	try {
		Form low = Form("Low", 151, 151);
		std::cout << low << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n------- Grade to low to sign --------------\n" << std::endl;
	beginner.signForm(form);

	std::cout << "\n------- Sign Test -------------------------\n" << std::endl;
	hermes.signForm(form);

	std::cout << "\n------- Destruction -----------------------\n" << std::endl;

	return (0);
}