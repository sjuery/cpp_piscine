#ifndef BUREAUCRAT_HPP
#define  BUREAUCRAT_HPP

# include <iostream>
# include <string>

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

	std::string getName();
	int getGrade();
	void increaseGrade();
	void decreaseGrade();
	void signForm(std::string, bool);
};

std::ostream& operator <<(std::ostream&, Bureaucrat&);
#endif
