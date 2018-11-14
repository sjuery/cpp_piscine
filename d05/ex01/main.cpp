#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "InvalidPerfectBureaucrat:" << std::endl;
	Bureaucrat IperfectBureaucrat("InvalidPerfectBureaucrat", 0);
	std::cout << IperfectBureaucrat;

	std::cout << "\nPerfectBureaucrat:" << std::endl;
	Bureaucrat perfectBureaucrat("PerfectBureaucrat", 1);
	std::cout << perfectBureaucrat;
	Form hardForm("HardForm", 1);
	std::cout << hardForm;
	perfectBureaucrat.decreaseGrade();
	std::cout << perfectBureaucrat;
	hardForm.beSigned(perfectBureaucrat);
	std::cout << hardForm;
	perfectBureaucrat.increaseGrade();
	std::cout << perfectBureaucrat;
	hardForm.beSigned(perfectBureaucrat);
	std::cout << hardForm;
	hardForm.beSigned(perfectBureaucrat);

	std::cout << "\nInvalidShitBureaucrat:" << std::endl;
	Bureaucrat IshitBureaucrat("InvalidShitBureaucrat", 0);
	std::cout << IshitBureaucrat;

	std::cout << "\nShitBureaucrat:" << std::endl;
	Bureaucrat shitBureaucrat("ShitBureaucrat", 150);
	std::cout << shitBureaucrat;
	shitBureaucrat.increaseGrade();
	std::cout << shitBureaucrat;
	return 0;
}
