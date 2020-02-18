#include <iostream>
#include "ClapTrap.hpp"
#include <ctime>

ClapTrap::ClapTrap( void ) {

	std::cout << "class ClapTrap default constructor is called" << std::endl;
	this->_HP = 100;
	this->_maxHP = 100;
	this->_lvl = 1;
	return;
}

ClapTrap::~ClapTrap ( void ) {

	std::cout << "class ClapTrap default destructor is called" << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {

	*this = src;
}

ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs ) {

	if ( this != &rhs ) {

		this->_HP = rhs.getHP();
		this->_maxHP = rhs.getMaxHP();
		this->_lvl = rhs.getlvl();
	}

	return *this;
}

uint32_t	ClapTrap::getHP( void ) const {

	return this->_HP;
}

uint32_t	ClapTrap::getMaxHP( void ) const {

	return this->_maxHP;
}

uint32_t	ClapTrap::getlvl( void ) const {

	return this->_lvl;
}

void	ClapTrap::_beRepaired( uint32_t amount ) {

	if ( this->_HP + amount > this->getMaxHP() )
		this->_HP = this->getMaxHP();
	else
		this->_HP += amount;
}
