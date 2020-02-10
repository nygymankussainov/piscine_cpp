#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void ) {

	return;
}

Zombie::~Zombie( void ) {

	return;
}

void	Zombie::announce( void ) const {

	std::cout << this->name + " (" << this->type + ") " << "Braiiiiiiinnnnssss...\n";
}
