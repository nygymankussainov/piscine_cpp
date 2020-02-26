#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy( int hp, std::string const & type ) {

	this->_type = type;
	this->_hp = hp;
	return;
}

Enemy::Enemy( Enemy const & src ) {

	*this = src;
}

Enemy::~Enemy( void ) {

	return;
}

Enemy &	Enemy::operator=( Enemy const & rhs ) {

	if ( this != &rhs ) {

		this->_type = rhs.getType();
		this->_hp = rhs.getHP();
	}

	return *this;
}

std::string	const	Enemy::getType( void ) const {

	return this->_type;
}

int		Enemy::getHP( void ) const {

	return this->_hp;
}

void	Enemy::takeDamage( int damage ) {

	if ( damage > 0 ) {

		this->_hp -= damage;
		if ( this->_hp < 0 )
			this->_hp = 0;
	}
}
