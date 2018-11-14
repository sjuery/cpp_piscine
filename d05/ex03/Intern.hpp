#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern ();
	Intern(Intern const & that);
	~Intern ();
	Intern& operator=(Intern const & that);

	struct NotAValidForm : public std::exception {
		const char * what () const throw () {
			return "Please input a valid form";
		}
	};

	Form* makeForm(std::string, std::string);
};
