#include "Fixed.class.hpp"

int const	Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) {

	std::cout << "Default constructor" << std::endl;
	this->_fixedPointVal = 0;
	return;
}

Fixed::Fixed( int const iVal ) {

	std::cout << "Int constructor" << std::endl;
	this->_fixedPointVal = iVal << _fractionalBits;
	return;
}

Fixed::Fixed( float const fVal ) {

	std::cout << "Float constructor" << std::endl;
	this->_fixedPointVal = roundf(fVal * (1 << _fractionalBits));
	return;
}

Fixed::Fixed( Fixed const & src ) {

	std::cout << "Copy constructor" << std::endl;
	*this = src;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor" << std::endl;
	return;
}

float	Fixed::toFloat( void ) const {

	std::cout << "toFloat" << std::endl;
	return ((float)(this->_fixedPointVal) / (1 << _fractionalBits));
}

int		Fixed::toInt( void ) const {

	std::cout << "toInt" << std::endl;
	return ((int)(this->_fixedPointVal >> _fractionalBits));
}

Fixed & Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Assignation operator" << std::endl;
	if (this != &rhs)
	{
		this->_fixedPointVal = (int)rhs._fixedPointVal;
	}

	return *this;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs ) {

	o << rhs.toFloat();
	return o;
}
