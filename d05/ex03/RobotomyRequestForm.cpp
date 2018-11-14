#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm (std::string target) {
	_name = "RobotomyRequest";
	_target = target;
	_requiredGrade = 72;
	_execGrade = 45;
	_signed = 0;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & that) {
	*this = that;
}

RobotomyRequestForm::~RobotomyRequestForm () {

}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & that) {
	*this = that;
	return *this;
}

void RobotomyRequestForm::specificExecution() const
{
	std::cout << "Rizzzzzz... Rizzzzzzz... Rizzzz... Riz..." << std::endl;
	if(rand()%2 == 1)
		std::cout << _target + " was successfully turned into a robot!" << std::endl;
	else
		std::cout << _target + " died in the process..." << std::endl;
}

int RobotomyRequestForm::execute(const Bureaucrat& src) const
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
