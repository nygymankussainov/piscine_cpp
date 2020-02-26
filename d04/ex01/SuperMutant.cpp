#include <iostream>
#include "Enemy.hpp"
#include "SuperMutant.hpp"

SuperMutant::SuperMutant( void ) : Enemy( 170, "Super Mutant" ) {

	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::SuperMutant( SuperMutant const & src ) : Enemy( src ) {

	return;
}

SuperMutant &	SuperMutant::operator=( SuperMutant const & rhs ) {

	if ( this != & rhs ) {

		Enemy::operator=( rhs );
	}

	return *this;
}

SuperMutant::~SuperMutant( void ) { 

	std::cout << "Aaargh ..." << std::endl;
	return;
}

void	SuperMutant::takeDamage( int damage ) {

	Enemy::takeDamage( damage - 3 );
}
