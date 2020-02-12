#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <cmath>

class Fixed {

	public:

		Fixed( void );
		Fixed( int const iVal );
		Fixed( float const fVal );
		Fixed( Fixed const & src );
		~Fixed( void );

		Fixed &	operator=( Fixed const & rhs );
		bool	operator>( Fixed const & rhs ) const;
		bool	operator<( Fixed const & rhs ) const;
		bool	operator>=( Fixed const & rhs ) const;
		bool	operator<=( Fixed const & rhs ) const;
		bool	operator==( Fixed const & rhs ) const;
		bool	operator!=( Fixed const & rhs ) const;

		Fixed	operator+( Fixed const & rhs );
		Fixed	operator-( Fixed const & rhs );
		Fixed	operator*( Fixed const & rhs );
		Fixed	operator/( Fixed const & rhs );

		Fixed &	operator++( void ); // ++prefix
		Fixed	operator++( int ); // postfix++
		Fixed &	operator--( void ); // --prefix
		Fixed	operator--( int ); // postfix--

		static Fixed &	min( Fixed & a, Fixed & b );
		static Fixed const &	min( Fixed const & a, Fixed const & b );
		static Fixed &	max( Fixed & a, Fixed & b );
		static Fixed const &	max( Fixed const & a, Fixed const & b );

		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getVal( void ) const;

	private:

		static int const	_fractionalBits;
		int					_fixedPointVal;
};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif
