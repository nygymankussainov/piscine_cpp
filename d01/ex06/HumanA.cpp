#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weaponType ) {

	this->name = name;
	this->weapon = &weaponType;
	return;
}

HumanA::~HumanA( void ) {

	return;
}

void	HumanA::attack( void ) {

	std::cout << this->name + " attacks with his ";
	std::cout << this->weapon->type << "\n";
}
