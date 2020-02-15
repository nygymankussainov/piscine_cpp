#include <iostream>
#include "FragTrap.hpp"

int		main( void ) {

	FragTrap naruto( "Naruto" );
	FragTrap sasuke("Sasuke");

	naruto.meleeAttack( "Sasuke" );
	sasuke.vaulthunter_dot_exe("Naruto");
	return 0;
}
