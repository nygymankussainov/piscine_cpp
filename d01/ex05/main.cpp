#include "Brain.hpp"
#include "Human.hpp"

int		main( void ) {

	Human bob;

	std::cout << bob.identify() << "\n";
	std::cout << bob.getBrain().identify() << "\n";
	return 0;
}
