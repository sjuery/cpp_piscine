#include "Form.hpp"

Form::Form() {

}

Form::Form(std::string name, int givenGrade) : _name(name), _requiredGrade(givenGrade), _signed(0), _execGrade(0)
{
	try
	{
		if(givenGrade < 1)
			throw GradeTooHighException();
		else if(givenGrade > 150)
			throw GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "Do not use!" << std::endl;
	}
	return ;
}

Form::Form(Form const & that) : _requiredGrade(that._requiredGrade), _execGrade(0) {
	*this = that;
	return ;
}

Form::~Form() {
	return ;
}

Form&	Form::operator=(Form const & that) {
	*this = that;
	return *this;
}

std::string Form::getName()
{
	return _name;
}

int Form::getGrade()
{
	return _requiredGrade;
}

bool Form::getSigned()
{
	return _signed;
}

int Form::getExecGrade()
{
	return _execGrade;
}

void Form::beSigned(Bureaucrat& src)
{
	if(!_signed)
	{
		try
		{
			if(src.getGrade() > _requiredGrade)
				throw GradeTooLowException();
			else
				_signed = 1;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << " and the form was not signed." << std::endl;
		}
		src.signForm(_name, _signed);
	}
	else
		std::cout << "Form is already signed" << std::endl;
}

void Bureaucrat::executeForm(Form const & form) {
	try
	{
		if(!form.execute(*this))
			throw FailedToExecute();
		else
			std::cout << "Successfully Executed File" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& stream, Form& src)
{
	if(src.getSigned())
    	stream << src.getName() << " is a signed Form with a grade requirement of " << src.getGrade() << " and an execution requirement of " <<  src.getExecGrade() << "." << std::endl;
	else
		stream << src.getName() << " is an unsigned Form with a grade requirement of " << src.getGrade() << " and an execution requirement of " <<  src.getExecGrade() << "." << std::endl;
    return (stream);
}
