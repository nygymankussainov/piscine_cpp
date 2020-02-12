#include "Fixed.class.hpp"

Fixed	Fixed::operator+( Fixed const & rhs ) {

	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-( Fixed const & rhs ) {

	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator/( Fixed const & rhs ) {

	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	Fixed::operator*( Fixed const & rhs ) {

	return (Fixed(this->toFloat() * rhs.toFloat()));
}

// ++prefix
Fixed &	Fixed::operator++( void ) {

	++this->_fixedPointVal;
	return *this;
}

// postfix++
Fixed	Fixed::operator++( int ) {

	Fixed	tmp(*this);

	operator++();
	return tmp;
}

// --prefix
Fixed &	Fixed::operator--( void ) {

	--this->_fixedPointVal;
	return *this;
}

// postfix--
Fixed	Fixed::operator--( int ) {

	Fixed	tmp(*this);

	operator--();
	return tmp;
}
