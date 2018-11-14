#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	srand(time(0));
	std::cout << "ShrubberyCreationForm:" << std::endl;
	Bureaucrat bob("Bob", 1);
	ShrubberyCreationForm scform("Home");
	std::cout << scform;
	scform.beSigned(bob);
	std::cout << scform;
	bob.executeForm(scform);

	std::cout << "\nRobotomyRequestForm:" << std::endl;
	RobotomyRequestForm rrform("Bob");
	std::cout << rrform;
	bob.executeForm(rrform);
	rrform.beSigned(bob);
	std::cout << rrform;
	bob.executeForm(rrform);

	std::cout << "\nPresidentialPardonForm:" << std::endl;
	Bureaucrat john("john", 24);
	PresidentialPardonForm ppform("John");
	std::cout << ppform;
	ppform.beSigned(john);
	std::cout << ppform;
	john.executeForm(ppform);
	bob.executeForm(ppform);
	return 0;
}
