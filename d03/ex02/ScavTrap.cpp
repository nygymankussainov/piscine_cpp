#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <ctime>

ScavTrap::ScavTrap( void ) {

	std::cout << "class ScavTrap default constructor is called" << std::endl;
	return;
}

ScavTrap::ScavTrap( std::string name ) {

	std::cout << "class ScavTrap parameterized constructor is called" << std::endl;
	this->_name = name;
	this->_EP = 50;
	this->_maxEP = 50;
	this->_MAdmg = 20;
	this->_RAdmg = 15;
	this->_armorDmgRed = 3;
	return;
}

ScavTrap::~ScavTrap ( void ) {

	std::cout << "class ScavTrap default destructor is called" << std::endl;
	return;
}

ScavTrap::ScavTrap( ScavTrap const & src ) {

	*this = src;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs ) {

	if ( this != &rhs ) {

		this->_name = rhs.getName();
		this->_EP = rhs.getEP();
		this->_maxEP = rhs.getMaxEP();
		this->_MAdmg = rhs.getMAdmg();
		this->_RAdmg = rhs.getRAdmg();
		this->_armorDmgRed = rhs.getArmorDmgRed();
	}

	return *this;
}

std::string	ScavTrap::getName( void ) const {

	return this->_name;
}

uint32_t	ScavTrap::getEP( void ) const {

	return this->_EP;
}

uint32_t	ScavTrap::getMaxEP( void ) const {

	return this->_maxEP;
}

uint32_t	ScavTrap::getMAdmg( void ) const {

	return this->_MAdmg;
}

uint32_t	ScavTrap::getRAdmg( void ) const {

	return this->_RAdmg;
}

uint32_t	ScavTrap::getArmorDmgRed( void ) const {

	return this->_armorDmgRed;
}

void		ScavTrap::rangedAttack( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " at range, causing " << this->getRAdmg() << " points of damage !"
		<< std::endl;
}

void		ScavTrap::meleeAttack( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " at close distance, causing " << this->getMAdmg() << " points of damage !"
		<< std::endl;
}

void	ScavTrap::_takeDamage( uint32_t amount ) {

	if ( this->_HP - amount + this->getArmorDmgRed() )
		this->_HP = 0;
	else
		this->_HP -= amount - this->getArmorDmgRed();
}

void	ScavTrap::challengeNewcomer( std::string const & target ) {

	std::string funnyChallenges[5] = { "ch1", "ch2", "ch3", "ch4", "ch5" };

	srand( time(NULL) );
	int i = rand() % 5;

	std::cout << this->_name << " challenges " << target << " to do "
		<< funnyChallenges[i] << std::endl;
}
