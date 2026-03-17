#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

// CONSTRUCTORS AND DESTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery Creation Form", 145, 137), _target("Default")
{
	std::cout << "Shrubbery creation form default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target) 
{
	std::cout << "Form " << this->getName() << " constructor called\nsign grade: "
			  << this->getSignGrade() << "\nexecute grade: " << this->getExecuteGrade()
			  << "\ntarget: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
	: AForm(copy), _target(copy._target) 
{
	std::cout << "Shrubbery creation form copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "Shrubbery creation form destructor called" << std::endl;
}

// OPERATOR OVERLOADS
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

// MEMBER FUNCTIONS
void	ShrubberyCreationForm::executeForm(void) const {
	std::ofstream	out((_target + "_shrubbery").c_str());
	if (!out)
	{
		std::cerr << "Failed to open shrubbery file." << std::endl;
		return;
	}
	out << "       _-_" << std::endl;
	out << "    /~~   ~~\\ " << std::endl;
	out << " /~~         ~~\\ " << std::endl;
	out << "{               }" << std::endl;
	out << " \\  _-     -_  /" << std::endl;
	out << "   ~  \\\\ //  ~" << std::endl;
	out << "_- -   | | _- _" << std::endl;
	out << "  _ -  | |   -_" << std::endl;
	out << "      // \\\\" << std::endl;
} 
