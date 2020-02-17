#include "ScavTrap.hpp"
#include "ClasTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( std::string name ) {

	std::cout << "ScavTrap Default constructor" << std::endl;
	this->_name = name;
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

void	ScavTrap::challengeNewcomer(std::string const & target) {

	std::string challenge[5] = { "take a cold shower.", "not sitting for a day.", "cut your hair.", "call your boss and tell him 'he is fired'.", "put a bottle of water in front of bocal." };
	srand( time(NULL) );
	int i = rand() % 5;
	std::cout << this->_name << ": I challenge " << target << " to " << challenge[i] << std::endl;
}
