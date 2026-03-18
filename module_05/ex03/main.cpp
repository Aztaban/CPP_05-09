#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main(void) {
	std::srand(std::time(0));
	std::cout << "\n------- Construction ----------------------\n" << std::endl;
	Bureaucrat	hermes = Bureaucrat("Hermes", 1);
	Intern		intern = Intern();
	AForm*		robotomy = 0;
	AForm*		president = 0;
	AForm*		shrub = 0;
	
	std::cout << "\n------- Invalid forms creation ------------\n" << std::endl;
	robotomy = intern.makeForm("robotomy request", "");
	robotomy = intern.makeForm("botomy request", "Bender");
	robotomy = intern.makeForm("", "Bender");
	
	std::cout << "\n------- Valid form creation ---------------\n" << std::endl;
	robotomy = intern.makeForm("robotomy request", "Bender");
	president = intern.makeForm("presidential pardon", "Stephen J. Fry");
	shrub = intern.makeForm("shrubbery creation", "42 Prague");
	
	std::cout << "\n------- Form object check -----------------\n" << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << *president << std::endl;
	std::cout << *shrub << std::endl;

	std::cout << "\n------- Sign sufficient grade -------------\n" << std::endl;
	hermes.signForm(*president);
	hermes.signForm(*robotomy);
	hermes.signForm(*shrub);

	std::cout << "\n------- Execute sufficient grade ----------\n" << std::endl;
	if (robotomy)
		hermes.executeForm(*robotomy);
	if (president)
		hermes.executeForm(*president);
	if (shrub)
		hermes.executeForm(*shrub);

	std::cout << "\n------- Destruction -----------------------\n" << std::endl;

	delete president;
	delete robotomy;
	delete shrub;

	return (0);
}