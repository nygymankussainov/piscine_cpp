#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int		main( void ) {

	Intern intern;
	Bureaucrat b1("b1", 150);
	Bureaucrat b2("b2", 45);
	Bureaucrat signer("signer", 150);
	Bureaucrat executor("executor", 150);
	OfficeBlock ob(intern, b1, b2);
	ShrubberyCreationForm f;

	b1.signForm(f);

	ob.setSigner(signer);
	ob.setExecutor(executor);
	ob.doBureaucraccy( "Shrubbery", "Anuar");
	return 0;
}
