#ifndef FORM_HPP
#define  FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	const std::string _name;
	const int _requiredGrade;
	bool _signed;
public:
	Form (std::string, int);
	Form(Form const & that);
	~Form ();
	Form& operator=(Form const & that);

	struct GradeTooHighException : public std::exception {
		const char * what () const throw () {
			return "Given grade requirement is too high";
		}
	};
	struct GradeTooLowException : public std::exception {
		const char * what () const throw () {
			return "Given grade requirement is too low";
		}
	};

	std::string getName();
	int getGrade();
	bool getSigned();
	void beSigned(Bureaucrat&);
};

std::ostream& operator <<(std::ostream&, Form&);
#endif
