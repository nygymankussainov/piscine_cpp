#include "Fixed.class.hpp"

int const	Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) {

	this->_fixedPointVal = 0;
	return;
}

Fixed::Fixed( int const iVal ) {

	this->_fixedPointVal = iVal << _fractionalBits;
	return;
}

Fixed::Fixed( float const fVal ) {

	this->_fixedPointVal = roundf(fVal * (1 << _fractionalBits));
	return;
}

Fixed::Fixed( Fixed const & src ) {

	*this = src;
}

Fixed::~Fixed( void ) {

	return;
}

float	Fixed::toFloat( void ) const {

	return ((float)(this->_fixedPointVal) / (1 << _fractionalBits));
}

int		Fixed::toInt( void ) const {

	return ((int)(this->_fixedPointVal >> _fractionalBits));
}

Fixed & Fixed::operator=( Fixed const & rhs ) {

	if (this != &rhs) {
		this->_fixedPointVal = (int)rhs._fixedPointVal;
	}

	return *this;
}

int		Fixed::getVal( void ) const {

	return this->_fixedPointVal;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return o;
}
