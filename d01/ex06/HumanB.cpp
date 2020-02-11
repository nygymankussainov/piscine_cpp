#include "HumanB.hpp"

HumanB::HumanB( std::string name ) {

	this->name = name;
	return;
}

HumanB::~HumanB( void ) {

	return;
}

void	HumanB::setWeapon(Weapon& weapon) {

	this->weapon = &weapon;
}

void	HumanB::attack( void ) {

	std::cout << this->name + " attacks with his ";
	std::cout << this->weapon->type << "\n";
}
