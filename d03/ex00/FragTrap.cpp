#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : _name( name ) {

	std::cout << "Default constructor" << std::endl;
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

	std::cout << "Copy constructor" << std::endl;
	*this = src;
	return;
}

FragTrap::~FragTrap( void ) {

	std::cout << "Destructor" << std::endl;
	return;
}

FragTrap &	FragTrap::operator=( FragTrap const & rhs ) {

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

void	FragTrap::rangedAttack( std::string const & target ) {

	std::cout << "FR4G-TP" << this->_name << " attacks " << target
		<< " at range, " << "causing " << this->_rangedAttackDmg 
		<< " points of damage !"<< std::endl;
}

void	FragTrap::meleeAttack( std::string const & target ) {

	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " in close combat, " << "causing " << this->_meleeAttackDmg 
		<< " points of damage !"<< std::endl;
}

void	FragTrap::fingerAttack( std::string const & target ) {

	std::cout << "OMG! FR4G-TP " << this->_name << " attacks " << target
		<< " using his finger only, causing " << this->_fingerAttackDmg
		<< " points of damage !" << std::endl;
}

void	FragTrap::nipplesAttack( std::string const & target ) {

	std::cout << "OMG! FR4G-TP " << this->_name << " attacks " << target
		<< " using forbidden nipples in vise technique, causing " << this->_nipplesAttackDmg
		<< " points of damage !" << std::endl;
}

void	FragTrap::noContactAttack( std::string const & target ) {

	std::cout << "LOL! FR4G-TP " << this->_name << " attacks " << target
		<< " using no contact martial arts, causing " << this->_noContactAttackDmg
		<< " points of damage..." << std::endl;
}

void	FragTrap::_takeDmg( unsigned int amount ) {

	std::cout << this->_name << " takes " << amount - this->_armorDmgReduction
		<< " amount of damage !" << std::endl;
	this->_hitPoints -= amount - this->_armorDmgReduction;
	if ( this->_hitPoints < 0 ) {

		std::cout << this->_name << " has died !" << std::endl;
		this->_hitPoints = 0;
	}
}

void	FragTrap::_beRepaired( unsigned int amount ) {

	this->_hitPoints += amount;
	if ( this->_hitPoints > this->_maxHitPoints ) {

		this->_hitPoints = this->_maxHitPoints;
	}
	std::cout << this->_name << " has been repaired and now has "
		<< this->_hitPoints << " amount of HP !" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {

	void ( FragTrap::*funcptr[5] )( std::string const & target ) = { &FragTrap::rangedAttack, &FragTrap::meleeAttack, &FragTrap::fingerAttack, &FragTrap::nipplesAttack, &FragTrap::noContactAttack };
	std::string attackTypes[5] = { "_rangedAttack,", "_meleeAttack", "_fingerAttack", "_nipplesAttack", "_noContactAttack" };
	srand( time(NULL) );
	int i = rand() % 5;
	(this->*funcptr[i])( target );
}
