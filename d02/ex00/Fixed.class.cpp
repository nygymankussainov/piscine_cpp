#include "Fixed.class.hpp"

Fixed::Fixed( void ) {

	std::cout << "Constructor\n";
	this->_fixedPointVal = 0;
	return;
}

Fixed::Fixed(Fixed const & src) {

	std::cout << "Copy constructor\n";
	*this = src;
	return;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor\n";
	return;
}

Fixed &		Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Assignation overload\n";

	if (this != &rhs)
		this->_fixedPointVal = rhs.getRawBits();

	return *this;
}

int			Fixed::getRawBits( void ) const {

	std::cout << "getRawBits()" << std::endl;
	return this->_fixedPointVal;
}

void		Fixed::setRawBits( int const raw ) {

	std::cout << "setRawBits()" << std::endl;
	this->_fixedPointVal = raw;
}

int const	Fixed::_fractionalBits = 8;
