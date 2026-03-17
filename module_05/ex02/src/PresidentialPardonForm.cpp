#include <iostream>
#include "PresidentialPardonForm.hpp"

// CONSTRUCTORS AND DESTRUCTOR
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Presidential Pardon Form", 25, 5), _target("Default")
{
	std::cout << "Presidential pardon form default constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "Form " << this->getName() << " constructor called\nsign grade: "
			  << this->getSignGrade() << "\nexecute grade: " << this->getExecuteGrade()
			  << "\ntarget: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
	: AForm(copy), _target(copy._target)
{
	std::cout << "Presidential pardon form copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "Presidential pardon form destructor called" << std::endl;
}

// OPERATOR OVERLOADS
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

// MEMBER FUNCTIONS
void	PresidentialPardonForm::executeForm(void) const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
} 
