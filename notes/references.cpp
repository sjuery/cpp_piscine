#include <iostream>

//Keep in mind that pointers should still be used as references can never be reassigned and can never be NULL

int main(void) {
	//Creating an int equals to 42
	int numberOfBalls = 42;

	//Good old pointer to the address of number of balls.
	int		*ballsPtr = &numberOfBalls;
	//References are like pointers except we don't need to dereference them to reach its value
	int		&ballsRef = numberOfBalls;

	//Printing number of balls through each mean, first its actual int, then its pointer, and then its References.
	//Notice how ballsRef isn't dereferenced.
	std::cout << numberOfBalls << *ballsPtr << ballsRef << std::endl;

	//Pointer to balls pointer is set to 21, therefore number of balls is now 21.
	*ballsPtr = 21;
	std::cout << numberOfBalls << std::endl;
	//Reference to ballsRef is set to 84, therefore number of balls is now 84
	ballsRef = 84;
	std::cout << numberOfBalls << std::endl;
}
