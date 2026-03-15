#include "Form.hpp"

// CONSTRUCTORS AND DESTRUCTOR
Form::Form(void) : _name("Default"), _signed(false), _sign_grade(150), _execute_grade(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int signGrade, int execGrade)
	: _name("Default"), _signed(false), _sign_grade(signGrade), _execute_grade(execGrade) {
	std::cout << "Form " << name << " constructor called sign grade: " << _sign_grade 
			  << " ,execute grade: " << _execute_grade << std::endl;
	if (_sign_grade < 1 || _execute_grade < 1)
		throw GradeTooHighException();
	if (_sign_grade > 150 || _execute_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy)
	: _name(copy._name), _sign_grade(copy._sign_grade), _execute_grade(copy._execute_grade) {
	std::cout << "Form copy constructor called" << std::endl;
	return;
}

Form::~Form(void) {
	std::cout << "Form default destructor called" << std::endl;
}

// OPERATOR OVERLOADS
Form&	Form::operator=(const Form& copy) {
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &copy) 
		this->_signed = copy._signed;
	return (*this);
}

// MEMBER FUNCTIONS
const std::string&	Form::getName(void) const {
	return (_name);
}

bool	Form::getSigned(void) const {
	return (_signed);
}

int	Form::getSignGrade(void) const {
	return (_sign_grade);
}

int	Form::getExecuteGrade(void) const {
	return (_execute_grade);
}



// EXCEPTIONS
const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade to high! (Highest 1)");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade to low! (Lowest 150)");
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form: " << form.getName() << "\nSigned: " <<  form.getSigned() << "\nSign grade: " 
	   << form.getSignGrade() << "\nExecution grade: " << form.getExecuteGrade(); 
	return (os);
}