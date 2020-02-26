#include <iostream>
#include "AWeapon.hpp"

AWeapon::AWeapon( std::string const & name, int apcost, int damage ) {

	this->_name = name;
	this->_damage = damage;
	this->_apcost = apcost;
	return;
}

AWeapon::AWeapon( AWeapon const & src ) {

	*this = src;
}

AWeapon &	AWeapon::operator=( AWeapon const & rhs ) {

	if ( this != &rhs ) {

		this->_name = rhs.getName();
		this->_apcost = rhs.getAPCost();
		this->_damage = rhs.getDamage();
	}

	return *this;
}

AWeapon::~AWeapon( void ) {

	return;
}

std::string const	AWeapon::getName( void ) const {

	return this->_name;
}

int			AWeapon::getAPCost( void ) const {

	return this->_apcost;
}

int			AWeapon::getDamage( void ) const {

	return this->_damage;
}
