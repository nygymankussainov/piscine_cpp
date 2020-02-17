#include "Fixed.class.hpp"

bool	Fixed::operator>( Fixed const & rhs  ) const {

	if (this != &rhs) {

		if (this->_fixedPointVal > rhs._fixedPointVal)
			return true;
	}
	return false;
}

bool	Fixed::operator<( Fixed const & rhs  ) const {
	if (this != &rhs) {

		if (this->_fixedPointVal < rhs._fixedPointVal)
			return true;
	}
	return false;
}

bool	Fixed::operator>=( Fixed const & rhs  ) const {

	if (this != &rhs) {

		if (this->_fixedPointVal >= rhs._fixedPointVal)
			return true;
	}
	return false;
}

bool	Fixed::operator<=( Fixed const & rhs  ) const {

	if (this != &rhs) {

		if (this->_fixedPointVal <= rhs._fixedPointVal)
			return true;
	}
	return false;
}

bool	Fixed::operator==( Fixed const & rhs  ) const {

	if (this != &rhs) {

		if (this->_fixedPointVal == rhs._fixedPointVal)
			return true;
	}
	return false;
}

bool	Fixed::operator!=( Fixed const & rhs  ) const {

	if (this != &rhs) {

		if (this->_fixedPointVal != rhs._fixedPointVal)
			return true;
	}
	return false;
}

Fixed &	Fixed::min( Fixed & a, Fixed & b ) {

	if ( a < b )
		return a;
	return b;
}

Fixed const &	Fixed::min( Fixed const & a, Fixed const & b ) {

	if ( a < b )
		return a;
	return b;
}

Fixed &	Fixed::max( Fixed & a, Fixed & b ) {

	if ( a > b )
		return a;
	return b;
}

Fixed const &	Fixed::max( Fixed const & a, Fixed const & b ) {

	if ( a > b )
		return a;
	return b;
}
