#include <iostream>
#include "RobotomyRequestForm.hpp"

// CONSTRUCTORS AND DESTRUCTOR
RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy Request Form", 72, 45), _target("Default")
{
	std::cout << "Robotomy Request form default constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "Form " << this->getName() << " constructor called\nsign grade: "
			  << this->getSignGrade() << "\nexecute grade: " << this->getExecuteGrade()
			  << "\ntarget: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
	: AForm(copy), _target(copy._target)
{
	std::cout << "Robotomy request form copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "Robotomy request form destructor called" << std::endl;
}

// OPERATOR OVERLOADS
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

// MEMBER FUNCTIONS
void	RobotomyRequestForm::executeForm(void) const {
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << std::endl;
} 

std::string	RobotomyRequestForm::getTarget(void) const {
	return (_target);
}