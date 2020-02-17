#include <iostream>
#include "ClasTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main( void ) {

	FragTrap ft( "FragTrap" );
	ScavTrap st( "ScavTrap" );

	ft.vaulthunter_dot_exe( "test" );
	st.challengeNewcomer( "test" );
	return 0;
}
