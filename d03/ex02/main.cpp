#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main( void ) {

	FragTrap ft( "FT" );
	FragTrap ft2 = ft;
	ScavTrap st( "ST" );
	ScavTrap st1 = st;

	std::cout << ft2.getHP() << std::endl;
	std::cout << st1.getHP() << std::endl;
	ft.vaulthunter_dot_exe( "Vlad" );
	st.challengeNewcomer( "Andrey" );
	return 0;
}
