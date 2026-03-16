#include "Bureaucrat.hpp"

// CONSTRUCTORS AND DESTRUCTOR
Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
	std::cout << "Bureacrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureacrat " << name << " constructor called with grade " << grade << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << "Bureacrat copy constructor called" << std::endl;
	return;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureacrat default destructor called" << std::endl;
}

// OPERATOR OVERLOADS
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy) {
	std::cout << "Bureacrat copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_grade = copy._grade;
	return (*this);
}

// MEMBER FUNCTIONS
const std::string&	Bureaucrat::getName(void) const {
	return (_name);
}

int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

void	Bureaucrat::incrementGrade(void) {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade(void) {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade to high! (Highest 1)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade to low! (Lowest 150)");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}