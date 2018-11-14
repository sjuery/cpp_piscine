#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm (std::string target) {
	_name = "PresidentialPardon";
	_target = target;
	_requiredGrade = 25;
	_execGrade = 5;
	_signed = 0;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & that) {
	*this = that;
}

PresidentialPardonForm::~PresidentialPardonForm () {

}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & that) {
	*this = that;
	return *this;
}

void PresidentialPardonForm::specificExecution() const
{
	std::cout << _target + " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

int PresidentialPardonForm::execute(const Bureaucrat& src) const
{
	try
	{
		if(src.getGrade() > _execGrade)
		{
			throw GradeTooLowException();
		}
		else if(!_signed)
		{
			throw FormNotSigned();
		}
		else
		{
			specificExecution();
			return 1;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 0;
	}
}
