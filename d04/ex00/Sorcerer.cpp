#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"

Sorcerer::Sorcerer( std::string name, std::string title ) {

	std::cout << name + ", " << title << ", is born !" << std::endl;
	this->_name = name;
	this->_title = title;
	return;
}

Sorcerer::~Sorcerer( void ) {

	std::cout << this->_name + ", " <<  this->_title
		<< ", is dead. Consequences will never be the same !" << std::endl;
	return;
}

Sorcerer::Sorcerer( Sorcerer const & src ) {

	*this = src;
}

Sorcerer &	Sorcerer::operator=( Sorcerer const & rhs ) {

	if ( this != &rhs ) {
		
		this->_name = rhs._name;
		this->_title = rhs._title;
	}

	return *this;
}

std::string	Sorcerer::getName( void ) const {

	return this->_name;
}

std::string Sorcerer::getTitle( void ) const {

	return this->_title;
}

void	Sorcerer::polymorph( Victim const & people ) const {

	people.getPolymorphed();
}

std::ostream &	operator<<( std::ostream & o, Sorcerer const & rhs ) {

	o << "I am " << rhs.getName() + ", "
		<< rhs.getTitle() << ", and I like ponies !"
		<< std::endl;
	return o;
}
