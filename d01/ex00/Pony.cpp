#include "Pony.hpp"

Pony::Pony( void ) {

	this->weight = 0;
	this->height = 0;
	return;
}

Pony::~Pony( void ) {

	return;
}

void	Pony::setParams(int weight, int height) {

	this->weight = weight;
	this->height = height;
}

void	Pony::setName(std::string name) {

	this->name = name;
}

void	Pony::setColor(std::string color) {

	this->color = color;
}
