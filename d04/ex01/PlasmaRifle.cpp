#include <iostream>
#include "AWeapon.hpp"

PlasmaRifle::PlasmaRifle( void ) :
	AWeapon( "Plasma Rifle", 5, 21 ) {

	return;
}

PlasmaRifle::PlasmaRifle( PlasmaRifle const & src ) : AWeapon( src ) {

	return;
}

PlasmaRifle &	PlasmaRifle::operator=( PlasmaRifle const & rhs ) {

	AWeapon::operator=( rhs );
	return *this;
}

PlasmaRifle::~PlasmaRifle( void ) {

	return;
}

void	PlasmaRifle::attack( void ) const {

	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
