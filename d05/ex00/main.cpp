#include "Bureaucrat.hpp"

int main() {
	std::cout << "InvalidPerfectBureaucrat:" << std::endl;
	Bureaucrat IperfectBureaucrat("InvalidPerfectBureaucrat", 160);
	std::cout << IperfectBureaucrat;

	std::cout << "\nPerfectBureaucrat:" << std::endl;
	Bureaucrat perfectBureaucrat("PerfectBureaucrat", 1);
	std::cout << perfectBureaucrat;
	perfectBureaucrat.increaseGrade();
	std::cout << perfectBureaucrat;

	std::cout << "\nInvalidShitBureaucrat:" << std::endl;
	Bureaucrat IshitBureaucrat("InvalidShitBureaucrat", 0);
	std::cout << IshitBureaucrat;

	std::cout << "\nShitBureaucrat:" << std::endl;
	Bureaucrat shitBureaucrat("ShitBureaucrat", 150);
	std::cout << shitBureaucrat;
	shitBureaucrat.decreaseGrade();
	std::cout << shitBureaucrat;
	return 0;
}
