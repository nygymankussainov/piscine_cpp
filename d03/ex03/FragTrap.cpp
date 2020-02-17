#include "ClasTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) {

	std::cout << "FragTrap Default constructor" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_lvl = 1;
	this->_nipplesAttackDmg = 40;
	this->_meleeAttackDmg = 30;
	this->_rangedAttackDmg = 20;
	this->_fingerAttackDmg = 10;
	this->_noContactAttackDmg = 0;
	this->_armorDmgReduction = 5;
	return;
}

FragTrap::FragTrap( FragTrap const & src ) {

	std::cout << "FragTrap Copy constructor" << std::endl;
	*this = src;
	return;
}

FragTrap::~FragTrap( void ) {

	std::cout << "FragTrap Destructor" << std::endl;
	return;
}

FragTrap &	FragTrap::operator=( FragTrap const & rhs ) {

	std::cout << "FragTrap Assignation operator" << std::endl;
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

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {

	void ( FragTrap::*funcptr[5] )( std::string const & target ) = { &FragTrap::rangedAttack, &FragTrap::meleeAttack, &FragTrap::fingerAttack, &FragTrap::nipplesAttack, &FragTrap::noContactAttack };
	std::string attackTypes[5] = { "_rangedAttack,", "_meleeAttack", "_fingerAttack", "_nipplesAttack", "_noContactAttack" };
	srand( time(NULL) );
	int i = rand() % 5;
	(this->*funcptr[i])( target );
}

std::string	FragTrap::getName( void ) const {

	return this->_name;
}
