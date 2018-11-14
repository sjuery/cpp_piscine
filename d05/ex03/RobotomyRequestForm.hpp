#ifndef ROBOTOMYREQUESTFORM_HPP
#define  ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
#include <fstream>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	std::string _target;
public:
	RobotomyRequestForm (std::string);
	RobotomyRequestForm(RobotomyRequestForm const & that);
	~RobotomyRequestForm ();
	RobotomyRequestForm& operator=(RobotomyRequestForm const & that);

	struct FormNotSigned : public std::exception {
		const char * what () const throw () {
			return "Form isn't signed yet";
		}
	};

	void specificExecution() const;
	int execute(const Bureaucrat& src) const;
};
#endif
