#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern {

public:
	Intern(void);
	Intern(const Intern& copy);

	Intern&	operator=(const Intern& copy);

	~Intern(void);

	AForm*	makeForm(const std::string& form, const std::string target);

};

#endif