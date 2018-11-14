#include <iostream>
#include "includes/classes.hpp"

//Function called when sample class is created, sets functions in sample class to arguments fed in
Sample::Sample(float const cc, char c1, int i1, float d1) : variable(cc), character(c1), integer(i1), decimal(d1) {
	Sample::_nbInstances++;
	//simply print the fact that an instance was created
	std::cout << "Sample Class Instance Created" << std::endl;

	std::cout << "character = " << character << std::endl;
	std::cout << "integer = " << integer << std::endl;
	std::cout << "decimal = " << decimal << std::endl;
	_privateFunction();
	return;
}

//Function called when sample class is destroyed.
Sample::~Sample(void) {
	//simply print the fact that an instance was destroyed
	std::cout << "Sample Class Instance Destroyed" << std::endl;
	Sample::_nbInstances--;
	return;
}

//Function declaired as const meaning no variables can be changed in this function
void Sample::function(void) const {
	//printing variable using the "this" keyword which points to our Sample Class
	std::cout << this->variable << std::endl;
	return;
}

int Sample::getNbInstances(void) {
	return(Sample::_nbInstances);
}

//Access the private variable without needing to be the in the Sample function
int Sample::getPrivateVariable(void) const {
	return _privateVariable;
}

//Modify the private Variable outside of the Sample function. Usually gives a restriction as to how it can be modified
void Sample::setPrivateVarible(int v) {
	_privateVariable = v;
}

//Private Function declaired as const meaning no variables can be changed in this function
void Sample::_privateFunction(void) const {
	std::cout << "Calling private function" << std::endl;
	return;
}

int main(void) {
	//Creating an instance of the Sample Class
	Sample instance(21, 'a', 42, 4.2f);
	//Calling function from our Sample class which remembered our previously set variable
	instance.function();
	std::cout << Sample::getNbInstances() << std::endl;
	//Returning therefore instance of class is destroyed and ~Sample is called
	return(0);
}

int Sample::_nbInstances = 0;
