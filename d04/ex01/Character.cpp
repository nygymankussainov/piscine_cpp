#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

Character::Character( std::string const & name ) {

	this->_name = name;
	this->_AP = 40;
	this->_currWeapon = NULL;
	return;
}

Character::Character( Character const & src ) {

	*this = src;
}

Character &	Character::operator=( Character const & rhs ) {

	if ( this != &rhs ) {

		this->_name = rhs.getName();
		this->_AP = rhs.getAP();
		this->_currWeapon = rhs.getAWeapon();
	}

	return *this;
}

Character::~Character( void ) {

	return;
}

std::string const	Character::getName( void ) const {

	return this->_name;
}

int		Character::getAP( void ) const {

	return this->_AP;
}

AWeapon *	Character::getAWeapon( void ) const {

	return this->_currWeapon;
}

void	Character::recoveryAP( void ) {

	this->_AP += 10;
	if ( this->_AP > 40 )
		this->_AP = 40;
}

void	Character::equip( AWeapon* weapon ) {

	this->_currWeapon = weapon;
	this->_AP -= weapon->getAPCost();
	if ( this->_AP < 0 )
		this->_AP = 0;
}

void	Character::attack( Enemy* target ) {

	if ( this->getAP() > 0 && this->getAWeapon() != NULL ) {

		std::cout << this->getName()
			<< " attacks " << target->getType()
			<< " with a " << this->getAWeapon()->getName()
			<< std::endl;
		this->getAWeapon()->attack();
		target->takeDamage( this->getAWeapon()->getDamage() );
		if ( target->getHP() <= 0 )
			target = NULL;
	}
}

std::ostream &	operator<<( std::ostream & o, Character const & rhs ) {

	o << rhs.getName() << " has "
		<< rhs.getAP() << " AP and ";
	if ( rhs.getAWeapon() != NULL )
		o << "wields a " << rhs.getAWeapon()->getName();
	else
		o << "is unarmed";
	o << std::endl;
	return o;
}
