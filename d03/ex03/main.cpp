#include <iostream>
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main( void ) {

	NinjaTrap ninja( "Naruto" );
	FragTrap ft( "Frag" );
	ScavTrap st( "Scav" );
	NinjaTrap nt( "Ninja" );

	ninja.ninjaShoebox( ft );
	ninja.ninjaShoebox( st );
	ninja.ninjaShoebox( nt );
	return 0;
}
