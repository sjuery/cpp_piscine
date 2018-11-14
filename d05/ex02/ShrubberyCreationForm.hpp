#ifndef SHRUBBERYCREATIONFORM_HPP
#define  SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
#include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	std::string _target;
public:
	ShrubberyCreationForm (std::string);
	ShrubberyCreationForm(ShrubberyCreationForm const & that);
	~ShrubberyCreationForm ();
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const & that);

	struct FormNotSigned : public std::exception {
		const char * what () const throw () {
			return "Form isn't signed yet";
		}
	};

	void specificExecution() const;
	int execute(const Bureaucrat& src) const;
};
#endif
