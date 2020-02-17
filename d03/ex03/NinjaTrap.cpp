#include "ClasTrap.hpp"
#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

NinjaTrap::NinjaTrap( std::string name ) {

	std::cout << "NinjaTrap Default constructor" << std::endl;
	this->_name = name;
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_lvl = 1;
	this->_nipplesAttackDmg = 70;
	this->_meleeAttackDmg = 60;
	this->_rangedAttackDmg = 5;
	this->_fingerAttackDmg = 65;
	this->_noContactAttackDmg = 80;
	this->_armorDmgReduction = 0;
	return;
}

NinjaTrap::NinjaTrap( NinjaTrap const & src ) {

	std::cout << "NinjaTrap Copy constructor" << std::endl;
	*this = src;
	return;
}

NinjaTrap::~NinjaTrap( void ) {

	std::cout << "NinjaTrap Destructor" << std::endl;
	return;
}

NinjaTrap &	NinjaTrap::operator=( NinjaTrap const & rhs ) {

	std::cout << "NinjaTrap Assignation operator" << std::endl;
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

void	NinjaTrap::ninjaShoebox( FragTrap & ft ) {

	std::cout << "Ninja " << this->_name << " attacks FragTrap " << ft.getName() << ":) ! he-he lol" << std::endl;
}

void	NinjaTrap::ninjaShoebox( ScavTrap & st ) {

	std::cout << "Ninja " << this->_name << " attacks ScavTrap :) " << st.getName() <<  " ! he-he kek" << std::endl;
}

void	NinjaTrap::ninjaShoebox( NinjaTrap & nt ) {

	std::cout << "Ninja " << this->_name << " attacks NinjaTrap :) " << nt.getName() << " ! he" << std::endl;
}

std::string	NinjaTrap::getName( void ) const {

	return this->_name;
}
