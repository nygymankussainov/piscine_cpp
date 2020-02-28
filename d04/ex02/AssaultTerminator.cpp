#include "ISpaceMarine.hpp"
#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator( void ) {

	std::cout << "* teleports from space *" << std::endl;
	return;
}

AssaultTerminator::AssaultTerminator( AssaultTerminator const & src ) {

	*this = src;
}

AssaultTerminator &	AssaultTerminator::operator=( AssaultTerminator const & rhs ) {

	if ( this != &rhs )
		return *this;
	return *this;
}

AssaultTerminator::~AssaultTerminator( void ) {

	std::cout << "I'll be back ..." << std::endl;
	return;
}

ISpaceMarine*	AssaultTerminator::clone( void ) const {

	ISpaceMarine* copy = new AssaultTerminator;
	return copy;
}

void			AssaultTerminator::battleCry( void ) const {

	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void			AssaultTerminator::rangedAttack( void ) const {

	std::cout << "* does nothing *" << std::endl;
}

void			AssaultTerminator::meleeAttack( void ) const {

	std::cout << "* attacks with chainfists *" << std::endl;
}
