#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( std::string name ) : _name( name ) {

	std::cout << "ScavTrap Default constructor" << std::endl;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_lvl = 1;
	this->_nipplesAttackDmg = 30;
	this->_meleeAttackDmg = 20;
	this->_rangedAttackDmg = 15;
	this->_fingerAttackDmg = 7;
	this->_noContactAttackDmg = 0;
	this->_armorDmgReduction = 3;
	return;
}

ScavTrap::ScavTrap( ScavTrap const & src ) {

	std::cout << "ScavTrap Copy constructor" << std::endl;
	*this = src;
	return;
}

ScavTrap::~ScavTrap( void ) {

	std::cout << "ScavTrap Destructor" << std::endl;
	return;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs ) {

	std::cout << "ScavTrap Assignation operator" << std::endl;
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

void	ScavTrap::rangedAttack( std::string const & target ) {

	std::cout << "ScavTrap FR4G-TP" << this->_name << " attacks " << target
		<< " at range, " << "causing " << this->_rangedAttackDmg 
		<< " points of damage !"<< std::endl;
}

void	ScavTrap::meleeAttack( std::string const & target ) {

	std::cout << "ScavTrap FR4G-TP " << this->_name << " attacks " << target
		<< " in close combat, " << "causing " << this->_meleeAttackDmg 
		<< " points of damage !"<< std::endl;
}

void	ScavTrap::fingerAttack( std::string const & target ) {

	std::cout << "ScavTrap OMG! FR4G-TP " << this->_name << " attacks " << target
		<< " using his finger only, causing " << this->_fingerAttackDmg
		<< " points of damage !" << std::endl;
}

void	ScavTrap::nipplesAttack( std::string const & target ) {

	std::cout << "ScavTrap OMG! FR4G-TP " << this->_name << " attacks " << target
		<< " using forbidden nipples in vise technique, causing " << this->_nipplesAttackDmg
		<< " points of damage !" << std::endl;
}

void	ScavTrap::noContactAttack( std::string const & target ) {

	std::cout << "ScavTrap LOL! FR4G-TP " << this->_name << " attacks " << target
		<< " using no contact martial arts, causing " << this->_noContactAttackDmg
		<< " points of damage..." << std::endl;
}

void	ScavTrap::_takeDmg( unsigned int amount ) {

	std::cout << "ScavTrap " << this->_name << " takes " << amount - this->_armorDmgReduction
		<< " amount of damage !" << std::endl;
	this->_hitPoints -= amount - this->_armorDmgReduction;
	if ( this->_hitPoints < 0 ) {

		std::cout << this->_name << " has died !" << std::endl;
		this->_hitPoints = 0;
	}
}

void	ScavTrap::_beRepaired( unsigned int amount ) {

	this->_hitPoints += amount;
	if ( this->_hitPoints > this->_maxHitPoints ) {

		this->_hitPoints = this->_maxHitPoints;
	}
	std::cout << "ScavTrap " << this->_name << " has been repaired and now has "
		<< this->_hitPoints << " amount of HP !" << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target) {

	std::string challenge[5] = { "take a cold shower.", "not sitting for a day.", "cut your hair.", "call your boss and tell him 'he is fired'.", "put a bottle of water in front of bocal." };
	srand( time(NULL) );
	int i = rand() % 5;
	std::cout << this->_name << ": I challenge " << target << " to " << challenge[i] << std::endl;
}
