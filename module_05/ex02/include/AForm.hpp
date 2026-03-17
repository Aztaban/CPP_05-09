#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <stdexcept>

class Bureaucrat;

class AForm {

public:
	AForm(void);
	AForm(const std::string& name, int signGrade, int execGrade);
	AForm(const AForm& copy);

	AForm&	operator=(const AForm& copy);
	
	~AForm(void);

	const std::string&	getName(void) const;
	bool				getSigned(void) const;
	int					getSignGrade(void) const;
	int					getExecuteGrade(void) const;

	void				beSigned(const Bureaucrat& bureaucrat);
	void				execute(Bureaucrat const& executor) const;

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

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

protected:
	virtual void	executeForm(void) const = 0;

private:
	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_execute_grade;

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif