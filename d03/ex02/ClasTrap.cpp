#include "ClasTrap.hpp"
#include <iostream>

ClasTrap::ClasTrap( void ) {

	std::cout << "Default constructor" << std::endl;
	this->_hitPoints = 0;
	this->_maxHitPoints = 0;
	this->_energyPoints = 0;
	this->_maxEnergyPoints = 0;
	this->_lvl = 0;
	this->_nipplesAttackDmg = 0;
	this->_meleeAttackDmg = 0;
	this->_rangedAttackDmg = 0;
	this->_fingerAttackDmg = 0;
	this->_noContactAttackDmg = 0;
	this->_armorDmgReduction = 0;
	return;
}

ClasTrap::ClasTrap( ClasTrap const & src ) {

	std::cout << "Copy constructor" << std::endl;
	*this = src;
	return;
}

ClasTrap::~ClasTrap( void ) {

	std::cout << "Destructor" << std::endl;
	return;
}

ClasTrap &	ClasTrap::operator=( ClasTrap const & rhs ) {

	std::cout << "Assignation operator" << std::endl;
	if (this != &rhs) {

		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_maxHitPoints = rhs._maxHitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_maxEnergyPoints = rhs._maxEnergyPoints;
		this->_lvl = rhs._lvl;
		this->_meleeAttackDmg = rhs._meleeAttackDmg;
		this->_rangedAttackDmg = rhs._rangedAttackDmg;
		this->_fingerAttackDmg = rhs._fingerAttackDmg;
		this->_nipplesAttackDmg = rhs._nipplesAttackDmg;
		this->_noContactAttackDmg = rhs._noContactAttackDmg;
		this->_armorDmgReduction = rhs._armorDmgReduction;
	}

	return *this;
}

void	ClasTrap::rangedAttack( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " at range, " << "causing " << this->_rangedAttackDmg 
		<< " points of damage !"<< std::endl;
}

void	ClasTrap::meleeAttack( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " in close combat, " << "causing " << this->_meleeAttackDmg 
		<< " points of damage !"<< std::endl;
}

void	ClasTrap::fingerAttack( std::string const & target ) {

	std::cout << "OMG! FR4G-TP " << this->_name << " attacks " << target
		<< " using his finger only, causing " << this->_fingerAttackDmg
		<< " points of damage !" << std::endl;
}

void	ClasTrap::nipplesAttack( std::string const & target ) {

	std::cout << "OMG! FR4G-TP " << this->_name << " attacks " << target
		<< " using forbidden nipples in vise technique, causing " << this->_nipplesAttackDmg
		<< " points of damage !" << std::endl;
}

void	ClasTrap::noContactAttack( std::string const & target ) {

	std::cout << "LOL! FR4G-TP " << this->_name << " attacks " << target
		<< " using no contact martial arts, causing " << this->_noContactAttackDmg
		<< " points of damage..." << std::endl;
}

void	ClasTrap::_takeDmg( unsigned int amount ) {

	std::cout << this->_name << " takes " << amount - this->_armorDmgReduction
		<< " amount of damage !" << std::endl;
	this->_hitPoints -= amount - this->_armorDmgReduction;
	if ( this->_hitPoints < 0 ) {

		std::cout << this->_name << " has died !" << std::endl;
		this->_hitPoints = 0;
	}
}

void	ClasTrap::_beRepaired( unsigned int amount ) {

	this->_hitPoints += amount;
	if ( this->_hitPoints > this->_maxHitPoints ) {

		this->_hitPoints = this->_maxHitPoints;
	}
	std::cout << this->_name << " has been repaired and now has "
		<< this->_hitPoints << " amount of HP !" << std::endl;
}
