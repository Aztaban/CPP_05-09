#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form {

public:
	Form(void);
	Form(const std::string& name, int signGrade, int execGrade);
	Form(const Form& copy);

	Form&	operator=(const Form& copy);
	
	~Form(void);

	const std::string&	getName(void) const;
	bool				getSigned(void) const;
	int					getSignGrade(void) const;
	int					getExecuteGrade(void) const;

	void				beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

private:
	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_execute_grade;

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif