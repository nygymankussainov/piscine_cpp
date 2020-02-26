#include <iostream>
#include "Enemy.hpp"
#include "RadScorpion.hpp"

RadScorpion::RadScorpion( void ) : Enemy( 80, "RadScorpion" ) {

	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::RadScorpion( RadScorpion const & src ) : Enemy( src ) {

	return;
}

RadScorpion &	RadScorpion::operator=( RadScorpion const & rhs ) {

	if ( this != & rhs ) {

		Enemy::operator=( rhs );
	}

	return *this;
}

RadScorpion::~RadScorpion( void ) { 

	std::cout << "* SPROTCH *" << std::endl;
	return;
}

void	RadScorpion::takeDamage( int damage ) {

	Enemy::takeDamage( damage );
}
