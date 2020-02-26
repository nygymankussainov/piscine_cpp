#include <iostream>
#include "AWeapon.hpp"

PowerFist::PowerFist( void ) :
	AWeapon( "Power Fist", 8, 50 ) {

	return;
}

PowerFist::PowerFist( PowerFist const & src ) : AWeapon( src ) {

	return;
}

PowerFist &	PowerFist::operator=( PowerFist const & rhs ) {

	AWeapon::operator=( rhs );
	return *this;
}

PowerFist::~PowerFist( void ) {

	return;
}

void	PowerFist::attack( void ) const {

	std::cout << "* pschhh... SBAM! *" << std::endl;
}
