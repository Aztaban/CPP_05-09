#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>
# include <iostream>

class AForm;

class Bureaucrat {

public:
	Bureaucrat(void);
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& copy);

	Bureaucrat&	operator=(const Bureaucrat& copy);

	~Bureaucrat(void);

	const std::string&	getName(void) const;
	int					getGrade(void) const;

	void				incrementGrade(void);
	void				decrementGrade(void);
	
	void				signForm(AForm& form) const;
	void				executeForm(AForm const& form) const;

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
	int					_grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif