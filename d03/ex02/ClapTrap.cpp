#include <iostream>
#include "ClapTrap.hpp"
#include <ctime>

ClapTrap::ClapTrap( void ) {

	std::cout << "class ClapTrap default constructor is called" << std::endl;
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

		this->_name = rhs.getName();
		this->_HP = rhs._HP;
		this->_maxHP = rhs._maxHP;
		this->_EP = rhs.getEP();
		this->_maxEP = rhs.getMaxEP();
		this->_lvl = rhs.getlvl();
		this->_MAdmg = rhs.getMAdmg();
		this->_RAdmg = rhs.getRAdmg();
		this->_armorDmgRed = rhs.getArmorDmgRed();
	}

	return *this;
}

void	ClapTrap::setAttributes( std::string name, uint32_t HP, uint32_t maxHP,
	   			   uint32_t EP, uint32_t maxEP, uint32_t lvl,
				   uint32_t MAdmg, uint32_t RAdmg, uint32_t armorDmgRed ) {

	this->_name = name;
	this->_HP = HP;
	this->_maxHP = maxHP;
	this->_EP = EP;
	this->_lvl = lvl;
	this->_maxEP = maxEP;
	this->_MAdmg = MAdmg;
	this->_RAdmg = RAdmg;
	this->_armorDmgRed = armorDmgRed;
}

std::string	ClapTrap::getName( void ) const {

	return this->_name;
}

uint32_t	ClapTrap::getHP( void ) const {

	return this->_HP;
}

uint32_t	ClapTrap::getMaxHP( void ) const {

	return this->_maxHP;
}

uint32_t	ClapTrap::getEP( void ) const {

	return this->_EP;
}

uint32_t	ClapTrap::getMaxEP( void ) const {

	return this->_maxEP;
}

uint32_t	ClapTrap::getlvl( void ) const {

	return this->_lvl;
}

uint32_t	ClapTrap::getMAdmg( void ) const {

	return this->_MAdmg;
}

uint32_t	ClapTrap::getRAdmg( void ) const {

	return this->_RAdmg;
}

uint32_t	ClapTrap::getArmorDmgRed( void ) const {

	return this->_armorDmgRed;
}

void		ClapTrap::rangedAttack( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " at range, causing " << this->getRAdmg() << " points of damage !"
		<< std::endl;
}

void		ClapTrap::meleeAttack( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " at close distance, causing " << this->getMAdmg() << " points of damage !"
		<< std::endl;
}

void	ClapTrap::_takeDamage( uint32_t amount ) {

	if ( this->_HP - amount + this->getArmorDmgRed() )
		this->_HP = 0;
	else
		this->_HP -= amount - this->getArmorDmgRed();
}
