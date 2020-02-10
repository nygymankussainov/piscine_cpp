#include "Human.hpp"

Human::Human( void ) {
	
	return;
}

Human::~Human( void ) {

	return;
}

std::string	Human::identify( void ) const {

	Brain brain = getBrain();
	return brain.identify();
}

Brain		Human::getBrain( void ) const {

	return this->brain;
}
