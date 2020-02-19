#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int		main( void ) {

	FragTrap ft( "FT" );
	FragTrap ft2 = ft;
	ScavTrap st( "ST" );
	ScavTrap st1 = st;
	NinjaTrap nt("Ninja");
	NinjaTrap nt1 = nt;

	std::cout << ft2.getHP() << std::endl;
	std::cout << nt1.getHP() << std::endl;
	std::cout << st1.getHP() << std::endl;
	ft.vaulthunter_dot_exe( "Vlad" );
	st.challengeNewcomer( "Andrey" );
	nt.ninjaShoebox( ft );
	nt.ninjaShoebox( st );
	nt.ninjaShoebox( nt1 );
	return 0;
}
