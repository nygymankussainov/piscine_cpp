#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <ctime>

SuperTrap::SuperTrap( void ) : ClapTrap(), FragTrap(), NinjaTrap() {

	std::cout << "class SuperTrap default constructor is called" << std::endl;
	return;
}

SuperTrap::SuperTrap( std::string name ) : ClapTrap(), FragTrap(name), NinjaTrap(name) {

	std::cout << "class SuperTrap parameterized constructor is called" << std::endl;
	ClapTrap::setAttributes( name, 100, 100, 120, 120, 1, 60, 20, 5 );
	return;
}

SuperTrap::~SuperTrap ( void ) {

	std::cout << "class SuperTrap default destructor is called" << std::endl;
	return;
}
