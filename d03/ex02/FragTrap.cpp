#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <ctime>

FragTrap::FragTrap( void ) {

	std::cout << "class FragTrap default constructor is called" << std::endl;
	return;
}

FragTrap::FragTrap( std::string name ) {

	std::cout << "class FragTrap parameterized constructor is called" << std::endl;
	ClapTrap::setAttributes( name, 100, 100, 100, 100, 1, 30, 20, 5 );
	return;
}

FragTrap::~FragTrap ( void ) {

	std::cout << "class FragTrap default destructor is called" << std::endl;
	return;
}

void	FragTrap::vaulthunter_dot_exe( std::string const & target ) {

	if ( this->getEP() < 25 ) {

		std::cout << "FR4G-TP " << this->_name << " doesn't have enough energy to run "
		<< "vaulthunter_dot_exe !" << std::endl;
	}

	srand( time( NULL ) );
	int i = rand() % 2;

	if ( i == 0 )
		rangedAttack( target );
	else
		meleeAttack( target );
}
