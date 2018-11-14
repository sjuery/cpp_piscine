#ifndef PRESIDENTIALPARDONFORM_HPP
#define  PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
#include <fstream>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	std::string _target;
public:
	PresidentialPardonForm (std::string);
	PresidentialPardonForm(PresidentialPardonForm const & that);
	~PresidentialPardonForm ();
	PresidentialPardonForm& operator=(PresidentialPardonForm const & that);

	struct FormNotSigned : public std::exception {
		const char * what () const throw () {
			return "Form isn't signed yet";
		}
	};

	void specificExecution() const;
	int execute(const Bureaucrat& src) const;
};
#endif
