#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & that) {
	*this = that;
	return ;
}

Intern::~Intern() {
}

Intern&	Intern::operator=(Intern const & that) {
	*this = that;
	return *this;
}

Form* Intern::makeForm(std::string type, std::string target)
{
	try
	{
		if(type == "shrubbery creation")
		{
			Form* newform = new ShrubberyCreationForm(target);
			std::cout << "Intern created " << type << std::endl;
			return newform;
		}
		else if(type == "robotomy request")
		{
			Form* newform = new RobotomyRequestForm(target);
			std::cout << "Intern created " << type << std::endl;
			return newform;
		}
		else if(type == "presidential pardon")
		{
			Form* newform = new PresidentialPardonForm(target);
			std::cout << "Intern created " << type << std::endl;
			return newform;
		}
		else
			throw NotAValidForm();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return NULL;
	}
}
