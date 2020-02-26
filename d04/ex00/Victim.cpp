#include <iostream>
#include "Victim.hpp"

Victim::Victim( std::string name ) {

	this->_name = name;
	std::cout << "Some random victim called "
		<< this->getName() << " just popped !"
		<< std::endl;
	return;
}

Victim::Victim( Victim const & src ) {

	std::cout << "Some random victim called "
		<< src.getName() << " just popped !"
		<< std::endl;
	*this = src;
}

Victim::~Victim( void ) {

	std::cout << "Victim " << this->getName()
	   << " just died for no apparent reason !"
	   << std::endl;
	return;
}

Victim &	Victim::operator=( Victim const & rhs ) {

	if ( this != &rhs ) {

		this->_name = rhs.getName();
	}
	return *this;
}

std::string	Victim::getName( void ) const {

	return this->_name;
}

void	Victim::getPolymorphed( void ) const {

	std::cout << this->getName()
		<< " has been turned into a cute little sheep !"
		<< std::endl;
}

std::ostream & operator<<( std::ostream & o, Victim const & rhs ) {

	o << "I am " << rhs.getName() << " and I like otters !"
		<< std::endl;
	return o;
}
