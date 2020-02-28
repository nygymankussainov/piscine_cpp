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

	this->_destroyUnits();
	this->_unitNb = 0;
	this->_copyUnits( src );
	this->_unitNb = src.getCount();
}

Squad &	Squad::operator=( Squad const & rhs ) {

	if ( this != &rhs ) {

		this->_destroyUnits();
		this->_unitNb = 0;
		this->_copyUnits( rhs );
		this->_unitNb = rhs.getCount();
	}
	return *this;
}

Squad::~Squad( void ) {

	_destroyUnits();
	return;
}

void	Squad::_copyUnits( Squad const & src ) {

	t_units *tmp = src.units;
	for ( int i = 0; i < src.getCount(); ++i ) {

		this->push( tmp->marine );
		tmp = tmp->next;
	}
}

void	Squad::_destroyUnits( void ) {

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
