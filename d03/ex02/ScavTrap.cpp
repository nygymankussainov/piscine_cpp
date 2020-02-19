#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <ctime>

ScavTrap::ScavTrap( void ) {

	std::cout << "class ScavTrap default constructor is called" << std::endl;
	return;
}

ScavTrap::ScavTrap( std::string name ) {

	std::cout << "class ScavTrap parameterized constructor is called" << std::endl;
	ClapTrap::setAttributes( name, 100, 100, 50, 50, 1, 20, 15, 3 );
	return;
}

ScavTrap::~ScavTrap ( void ) {

	std::cout << "class ScavTrap default destructor is called" << std::endl;
	return;
}

void	ScavTrap::challengeNewcomer( std::string const & target ) {

	std::string funnyChallenges[5] = { "ch1", "ch2", "ch3", "ch4", "ch5" };

	srand( time(NULL) );
	int i = rand() % 5;

	std::cout << this->_name << " challenges " << target << " to do "
		<< funnyChallenges[i] << std::endl;
}
