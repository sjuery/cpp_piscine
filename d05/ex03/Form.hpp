#ifndef FORM_HPP
#define  FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
protected:
	std::string _name;
	int _requiredGrade;
	int _execGrade;
	bool _signed;
public:
	Form();
	Form (std::string, int);
	Form(Form const & that);
	virtual ~Form ();
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

	virtual int execute(const Bureaucrat&) const = 0;
	std::string getName();
	int getGrade();
	bool getSigned();
	void beSigned(Bureaucrat&);
	int getExecGrade();
};

std::ostream& operator <<(std::ostream&, Form&);
#endif
