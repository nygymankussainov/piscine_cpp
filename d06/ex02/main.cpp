#include <iostream>
#include <stdexcept>
#include "Base.hpp"

Base*	generate( void ) {

	Base * random = NULL;
	srand(time(0));
	int i = rand() % 3;
	if ( i == 0 )
		random = new A;
	else if ( i == 1 )
		random = new B;
	else if ( i == 2 )
		random = new C;
	return random;
}

void	identify_from_pointer( Base * p ) {

	if ( dynamic_cast<A*> (p) )
		std::cout << "type A" << std::endl;
	else if ( dynamic_cast<B*> (p) )
		std::cout << "type B" << std::endl;
	else if ( dynamic_cast<C*> (p) )
		std::cout << "type C" << std::endl;
}

void	identify_from_reference( Base & p ) {

	try {

		Base& typeA = dynamic_cast<A&> (p);
		static_cast<void> (typeA);
		std::cout << "type A" << std::endl;
	}
	catch ( std::exception & e ) {

		try {

			Base& typeB = dynamic_cast<B&> (p);
			static_cast<void> (typeB);
			std::cout << "type B" << std::endl;
		}
		catch ( std::exception & e ) {

			try {

				Base& typeC = dynamic_cast<C&> (p);
				static_cast<void> (typeC);
				std::cout << "type C" << std::endl;
			}
			catch ( std::exception & e ) {

				std::cerr << e.what() << std::endl;
			}
		}
	}
}

int		main( void ) {

	Base* random = generate();
	identify_from_pointer( random );
	identify_from_reference( *random );
	return 0;
}
