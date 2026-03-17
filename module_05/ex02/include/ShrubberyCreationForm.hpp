#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"


class ShrubberyCreationForm : public AForm {

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& form);

	void	executeForm(void) const;

	~ShrubberyCreationForm(void);

private:
	std::string	_target;

};

#endif