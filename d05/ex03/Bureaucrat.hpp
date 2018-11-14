#ifndef BUREAUCRAT_HPP
#define  BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Form;
class Bureaucrat
{
	const std::string _name;
	int _grade;
public:
	Bureaucrat (std::string, int);
	Bureaucrat(Bureaucrat const & that);
	~Bureaucrat ();
	Bureaucrat& operator=(Bureaucrat const & that);

	struct GradeTooHighException : public std::exception {
		const char * what () const throw () {
			return "Given grade is too high, defaulted to ";
		}
	};
	struct GradeTooLowException : public std::exception {
		const char * what () const throw () {
			return "Given grade is too low, defaulted to ";
		}
	};
	struct FailedToExecute : public std::exception {
		const char * what () const throw () {
			return "Failed to execute form";
		}
	};

	std::string getName();
	int getGrade() const;
	void increaseGrade();
	void decreaseGrade();
	void signForm(std::string, bool);
	void executeForm(Form const & form);
};

std::ostream& operator <<(std::ostream&, Bureaucrat&);
#endif
