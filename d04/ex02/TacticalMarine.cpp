#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine( void ) {

	std::cout << "Tactical Marine ready for battle" << std::endl;
	return;
}

TacticalMarine::TacticalMarine( TacticalMarine const & src ) {

	*this = src;
}

TacticalMarine &	TacticalMarine::operator=( TacticalMarine const & rhs ) {

	if ( this != &rhs )
		return *this;
	return *this;
}

TacticalMarine::~TacticalMarine( void ) {

	std::cout << "Aaargh..." << std::endl;
	return;
}

ISpaceMarine*	TacticalMarine::clone( void ) const {

	ISpaceMarine* copy = new TacticalMarine;
	return copy;
}

void			TacticalMarine::battleCry( void ) const {

	std::cout << "For the holy PLOT" << std::endl;
}

void			TacticalMarine::rangedAttack( void ) const {

	std::cout << "* attacks with botler *" << std::endl;
}

void			TacticalMarine::meleeAttack( void ) const {

	std::cout << "* attacks with chainsword *" << std::endl;
}
