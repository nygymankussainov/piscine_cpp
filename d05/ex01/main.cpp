#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main( void ) {

	Bureaucrat b("John");
	Form f("28B", 100, 100);

	b.setGrade( -1 );
	b.signForm(f);
	return 0;
}
