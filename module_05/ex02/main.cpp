#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void) {
	std::srand(std::time(0));
	std::cout << "\n------- Construction ----------------------\n" << std::endl;
	Bureaucrat	hermes = Bureaucrat("Hermes", 1);
	Bureaucrat	beginner = Bureaucrat("Bob", 150);
	AForm*		president = new PresidentialPardonForm("Stephen J. Fry");
	AForm*		robotomy = new RobotomyRequestForm("Bender Bending Rodriguez");
	AForm*		shrub = new ShrubberyCreationForm("42 Prague");
	std::cout << "\n------- Objects check ---------------------\n" << std::endl;
	std::cout << *president << std::endl << std::endl;
	std::cout << *robotomy << std::endl << std::endl;
	std::cout << *shrub << std::endl << std::endl;
	std::cout << "\n------- Execute not signed check ----------\n" << std::endl;
	hermes.executeForm(*president);
	hermes.executeForm(*robotomy);
	hermes.executeForm(*shrub);
	std::cout << "\n------- Sign low grade --------------------\n" << std::endl;
	beginner.signForm(*president);
	beginner.signForm(*robotomy);
	beginner.signForm(*shrub);
	std::cout << "\n------- Sign sufficient grade -------------\n" << std::endl;
	hermes.signForm(*president);
	hermes.signForm(*robotomy);
	hermes.signForm(*shrub);
	std::cout << "\n------- Execute low grade -----------------\n" << std::endl;
	beginner.executeForm(*president);
	beginner.executeForm(*robotomy);
	beginner.executeForm(*shrub);
	std::cout << "\n------- Execute sufficient grade ----------\n" << std::endl;
	hermes.executeForm(*president);
	hermes.executeForm(*robotomy);
	hermes.executeForm(*shrub);
	std::cout << "\n------- Destruction -----------------------\n" << std::endl;
	delete president;
	delete robotomy;
	delete shrub;
	return (0);
}