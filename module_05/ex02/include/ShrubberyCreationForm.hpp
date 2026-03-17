#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"


class ShruberryCreationForm : public AForm {

public:
	ShruberryCreationForm(void);
	ShruberryCreationForm(const std::string& target);
	ShruberryCreationForm(const ShruberryCreationForm& copy);
	
	ShruberryCreationForm&	operator=(const ShruberryCreationForm& form);

	void	executeForm(void) const;

	~ShruberryCreationForm(void);

private:
	const std::string	_target;

};

#endif