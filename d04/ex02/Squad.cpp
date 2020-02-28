#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include "Squad.hpp"
#include <iostream>

Squad::Squad( void ) {

	this->units = NULL;
	this->_unitNb = 0;
	return;
}

Squad::Squad( Squad const & src ) {

	*this = src;
}

Squad &	Squad::operator=( Squad const & rhs ) {

	this->_unitNb = rhs._unitNb;
	this->units = NULL;
	Squad tmp = rhs;
	t_units *head = NULL;
	while ( tmp.units ) {
		
		t_units *newUnits = new t_units;
		newUnits->next = NULL;
		newUnits->marine = tmp.units->marine->clone();
		newUnits->index = tmp.units->index;
		if ( this->units == NULL) {

			this->units = newUnits;
			head = this->units;
		}
		else {

			this->units->next = newUnits;
			this->units = this->units->next;
		}
		tmp.units = tmp.units->next;
	}
	this->units = head;
	return *this;
}

Squad::~Squad( void ) {

	destroyUnits();
	return;
}

void	Squad::destroyUnits( void ) {

	while ( this->units ) {

		t_units *tmp = this->units->next;
		delete this->units->marine;
		delete this->units;
		this->units = tmp;
	}
}

int		Squad::getCount( void ) const {

	return this->_unitNb;
}

ISpaceMarine*	Squad::getUnit( int index ) const {

	if ( index > this->_unitNb || index < 0 )
		return nullptr;
	t_units *tmp = this->units;
	while ( tmp ) {

		if ( tmp->index == index )
			return tmp->marine;
		tmp = tmp->next;
	}
	return nullptr;
}

t_units	*Squad::find_unit( t_units* units, ISpaceMarine *marine ) {

	t_units *tmp = units;
	if ( tmp && tmp->marine == marine )
		return NULL;
	while ( tmp && tmp->next ) {

		if ( tmp->marine == marine )
			return NULL;
		tmp = tmp->next;
	}
	return tmp;
}

int		Squad::push( ISpaceMarine* marine ) {

	t_units *tmp = find_unit( this->units, marine );
	if ( tmp == NULL && this->_unitNb > 0 )
		return this->_unitNb;
	t_units *newUnit = new t_units;
	newUnit->next = NULL;
	newUnit->index = this->_unitNb;
	newUnit->marine = marine;
	if ( this->units == NULL )
		this->units = newUnit;
	else
		tmp->next = newUnit;
	++this->_unitNb;
	return this->_unitNb;
}
