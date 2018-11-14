#include <iostream>

int main(void) {
	char buff[512];

	//Access standard output and print the following, followed by a new line
	std::cout << "Hello World!" << std::endl;
	//Access standard input and redirect it to the buffer
	std::cin >> buff;
	//Access standard output and print the buffer
	std::cout << "You entered: [" << buff << "]" << std::endl;
	return(0);
}
