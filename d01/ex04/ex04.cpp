#include <iostream>

int main(void) {
	std::string brain = "HI THIS IS BRAIN";

	std::string &brain_ref = brain;
	std::string *brain_ptr = &brain;

	std::cout << "Original: " << brain << std::endl;
	std::cout << "Pointer: " << *brain_ptr << std::endl;
	std::cout << "Reference: " << brain_ref << std::endl;
}
