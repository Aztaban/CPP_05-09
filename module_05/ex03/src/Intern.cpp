#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// HELPERS
static int	getIndex(const std::string& form) {
	if (form == "presidential pardon")
		return (0);
	if (form == "robotomy request")
		return (1);
	if (form == ("shrubbery creation"))
		return (2);
	return (-1);
}

// CONSTRUCTORS AND DESTRUCTOR
Intern::Intern(void) {
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern& copy) {
	std::cout << "Intern copy constructor called." << std::endl;
	*this = copy;
}

Intern::~Intern(void) {
	std::cout << "Intern destructor called." << std::endl;
}

// OPERATOR OVERLOADS
Intern& Intern::operator=(const Intern& copy) {
	std::cout << "Intern copy operator called" << std::endl;
	(void)copy;
	return (*this);
}

// MEMBER FUNCTIONS
AForm*	Intern::makeForm(const std::string& form, const std::string target) {
	if (form.empty()) {
		std::cerr << "Form field is emtpy. Cannot create the form." << std::endl;
		return (0);
	}
	if (target.empty()) {
		std::cerr << "Target field is empty. Cannot create the form." << std::endl;
		return (0);
	}

	int	index = getIndex(form);
	switch (index) {
		case 0:
			std::cout << "Intern creates presidential pardon form." << std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << "Intern creates robotomy request form." << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates shrubbery creation form." << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			std::cerr << "Form " << form << " doesn't exist" << std::endl;
			return (0);
	}
}
