#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int givenGrade) : _name(name)
{
	try
	{
		if(givenGrade < 1)
			throw GradeTooHighException();
		else if(givenGrade > 150)
			throw GradeTooLowException();
		else
			_grade = givenGrade;
	}
	catch (std::exception& e)
	{
		_grade = 75;
		std::cout << e.what() << _grade << std::endl;
	}
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & that) {
	*this = that;
	return ;
}

Bureaucrat::~Bureaucrat() {
	return ;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & that) {
	if (this != &that) {
		_name = that._name;
		_grade = that._grade;
	}
	return *this;
}

std::string Bureaucrat::getName()
{
	return _name;
}

int Bureaucrat::getGrade()
{
	return _grade;
}

void Bureaucrat::increaseGrade()
{
	try
	{
		if(getGrade() - 1 < 1)
			throw GradeTooHighException();
		else
			_grade--;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << _grade << std::endl;
	}
}

void Bureaucrat::decreaseGrade()
{
	try
	{
		if(getGrade() + 1 > 150)
			throw GradeTooLowException();
		else
			_grade++;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << _grade << std::endl;
	}
}

std::ostream& operator<<(std::ostream& stream, Bureaucrat& src) {
    stream << src.getName() << " is a Bureaucrat with a grade of " << src.getGrade() << "." << std::endl;
    return (stream);
}
