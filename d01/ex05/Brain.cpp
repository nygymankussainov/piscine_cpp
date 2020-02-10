#include "Brain.hpp"
#include <sstream>

Brain::Brain( void ) {

	this->size = 0;
	this->weight = 0;
	return;
}

Brain::~Brain( void ) {

	return;
}

std::string	Brain::identify( void ) {

	std::stringstream address;

	address << this;
	this->_address = address.str();
	return this->_address;
}
