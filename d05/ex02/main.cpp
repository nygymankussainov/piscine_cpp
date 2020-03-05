#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main( void ) {

	ShrubberyCreationForm f("test");
	RobotomyRequestForm rob;
	PresidentialPardonForm p("Alex");
	Bureaucrat b("John");

	b.setGrade(1);
	b.signForm(rob);
	b.executeForm(rob);
	b.signForm(p);
	b.executeForm(p);
	b.setGrade(130);
	b.signForm(f);
	b.executeForm(f);
	return 0;
}
