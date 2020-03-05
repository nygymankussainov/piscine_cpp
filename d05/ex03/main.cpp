#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int		main( void ) {

	Intern intern;
	Form *form;
	Bureaucrat b;

	form = intern.makeForm("Presidential", "test");
	delete form;
	return 0;
}
