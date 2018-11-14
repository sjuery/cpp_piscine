#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	srand(time(0));

	Intern someRandomIntern;
	Form* rrf;

	std::cout << "ShrubberyCreationForm:" << std::endl;
	Bureaucrat bob("Bob", 1);
	rrf = someRandomIntern.makeForm("shrubbery creation", "home");
	std::cout << *rrf;
	rrf->beSigned(bob);
	std::cout << *rrf;
	bob.executeForm(*rrf);

	std::cout << "\nRobotomyRequestForm:" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "bob");
	std::cout << *rrf;
	bob.executeForm(*rrf);
	rrf->beSigned(bob);
	std::cout << *rrf;
	bob.executeForm(*rrf);

	std::cout << "\nPresidentialPardonForm:" << std::endl;
	Bureaucrat john("john", 24);
	rrf = someRandomIntern.makeForm("presidential pardon", "john");
	std::cout << *rrf;
	rrf->beSigned(john);
	std::cout << *rrf;
	john.executeForm(*rrf);
	bob.executeForm(*rrf);
	return 0;
}
