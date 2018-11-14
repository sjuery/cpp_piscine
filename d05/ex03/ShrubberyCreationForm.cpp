#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm (std::string target) {
	_name = "ShrubberyCreation";
	_target = target;
	_requiredGrade = 145;
	_execGrade = 137;
	_signed = 0;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & that) {
	*this = that;
}

ShrubberyCreationForm::~ShrubberyCreationForm () {

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & that) {
	*this = that;
	return *this;
}

void ShrubberyCreationForm::specificExecution() const
{
	std::ofstream outfile (_target + "_shrubbery");
	outfile << "ASCII trees!" << std::endl;
}

int ShrubberyCreationForm::execute(const Bureaucrat& src) const
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
