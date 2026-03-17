#include "AForm.hpp"
#include "Bureaucrat.hpp"

// CONSTRUCTORS AND DESTRUCTOR
AForm::AForm(void) : _name("Default"), _signed(false), _sign_grade(150), _execute_grade(150) {
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
	: _name("Default"), _signed(false), _sign_grade(signGrade), _execute_grade(execGrade) {
	std::cout << "Form " << name << " constructor called sign grade: " << _sign_grade 
			  << " ,execute grade: " << _execute_grade << std::endl;
	if (_sign_grade < 1 || _execute_grade < 1)
		throw GradeTooHighException();
	if (_sign_grade > 150 || _execute_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy)
	: _name(copy._name), _sign_grade(copy._sign_grade), _execute_grade(copy._execute_grade) {
	std::cout << "Form copy constructor called" << std::endl;
	return;
}

AForm::~AForm(void) {
	std::cout << "Form default destructor called" << std::endl;
}

// OPERATOR OVERLOADS
AForm&	AForm::operator=(const AForm& copy) {
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &copy) 
		this->_signed = copy._signed;
	return (*this);
}

// MEMBER FUNCTIONS
const std::string&	AForm::getName(void) const {
	return (_name);
}

bool	AForm::getSigned(void) const {
	return (_signed);
}

int	AForm::getSignGrade(void) const {
	return (_sign_grade);
}

int	AForm::getExecuteGrade(void) const {
	return (_execute_grade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_signed = true;
}

// EXCEPTIONS
const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade to high! (Highest 1)");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade to low! (Lowest 150)");
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form: " << form.getName() << "\nSigned: " <<  form.getSigned() << "\nSign grade: " 
	   << form.getSignGrade() << "\nExecution grade: " << form.getExecuteGrade(); 
	return (os);
}