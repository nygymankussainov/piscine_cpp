#include <iostream>
#include "ScavTrap.hpp"

int		main( void ) {

	ScavTrap st( "Eltac" );
	ScavTrap st2 = st;

	st2.challengeNewcomer( "Iles" );
	return 0;
}
