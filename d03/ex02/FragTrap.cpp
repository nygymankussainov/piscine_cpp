#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <ctime>

FragTrap::FragTrap( void ) {

	std::cout << "class FragTrap default constructor is called" << std::endl;
	return;
}

FragTrap::FragTrap( std::string name ) {

	std::cout << "class FragTrap parameterized constructor is called" << std::endl;
	this->_name = name;
	this->_EP = 100;
	this->_maxEP = 100;
	this->_MAdmg = 30;
	this->_RAdmg = 20;
	this->_armorDmgRed = 5;
	return;
}

FragTrap::~FragTrap ( void ) {

	std::cout << "class FragTrap default destructor is called" << std::endl;
	return;
}

FragTrap::FragTrap( FragTrap const & src ) {

	*this = src;
}

FragTrap &	FragTrap::operator=( FragTrap const & rhs ) {

	if ( this != &rhs ) {

		this->_name = rhs.getName();
		this->_EP = rhs.getEP();
		this->_maxEP = rhs.getMaxEP();
		this->_lvl = rhs.getlvl();
		this->_MAdmg = rhs.getMAdmg();
		this->_RAdmg = rhs.getRAdmg();
		this->_armorDmgRed = rhs.getArmorDmgRed();
	}

	return *this;
}

std::string	FragTrap::getName( void ) const {

	return this->_name;
}

uint32_t	FragTrap::getEP( void ) const {

	return this->_EP;
}

uint32_t	FragTrap::getMaxEP( void ) const {

	return this->_maxEP;
}

uint32_t	FragTrap::getMAdmg( void ) const {

	return this->_MAdmg;
}

uint32_t	FragTrap::getRAdmg( void ) const {

	return this->_RAdmg;
}

uint32_t	FragTrap::getArmorDmgRed( void ) const {

	return this->_armorDmgRed;
}

void		FragTrap::rangedAttack( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " at range, causing " << this->getRAdmg() << " points of damage !"
		<< std::endl;
}

void		FragTrap::meleeAttack( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " at close distance, causing " << this->getMAdmg() << " points of damage !"
		<< std::endl;
}

void	FragTrap::_takeDamage( uint32_t amount ) {

	if ( this->_HP - amount + this->getArmorDmgRed() )
		this->_HP = 0;
	else
		this->_HP -= amount - this->getArmorDmgRed();
}

void	FragTrap::vaulthunter_dot_exe( std::string const & target ) {

	if ( this->getEP() < 25 ) {

		std::cout << "FR4G-TP " << this->_name << " doesn't have enough energy to run "
		<< "vaulthunter_dot_exe !" << std::endl;
	}

	srand( time( NULL ) );
	int i = rand() % 2;

	if ( i == 0 )
		rangedAttack( target );
	else
		meleeAttack( target );
}
