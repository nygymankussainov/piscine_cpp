#include <iostream>
#include "Bureaucrat.hpp"

int		main(void) {

	Bureaucrat test("john");

	try {

		test.setGrade(0);
	}
	catch ( const std::exception & e ) {

		std::cerr << e.what() << std::endl;
	}
	return 0;
}