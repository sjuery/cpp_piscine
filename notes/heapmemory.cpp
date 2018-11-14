#include <iostream>
#include <string>

class Student {
private:
	std::string _login;

public:
	Student() : _login("random_student") {
		std::cout << "Student " << _login << " is born!" << std::endl;
	}

	~Student(void) {
		std::cout << "Student " << _login << " died..." << std::endl;
	}
};

int main(void) {
	//Student allocated on stack (Will die at end of loop, program, statment depending on when it is created)
	Student		stan;
	//Student created on heap (Will die when delete "alix" is called)
	Student*	alix = new Student;
	//Array of students created on heap (Will ALL die when delete "many" is called)
	Student*	many = new Student[42];

	//Deletes the whole array of students "many"
	delete [] many;
	//Deletes the student alix
	delete alix;
	//EOF Main therefore stan is deleted
}
