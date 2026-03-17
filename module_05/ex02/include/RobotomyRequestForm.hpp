#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& form);

	void		executeForm(void) const;
	std::string	getTarget(void) const;

	~RobotomyRequestForm(void);

private:
	std::string	_target;

};

#endif