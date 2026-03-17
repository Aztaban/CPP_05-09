#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"


class PresidentialPardonForm : public AForm {

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& form);

	void	executeForm(void) const;

	~PresidentialPardonForm(void);

private:
	const std::string	_target;

};

#endif