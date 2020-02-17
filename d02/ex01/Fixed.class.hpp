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

		float	toFloat( void ) const;
		int		toInt( void ) const;
		float	getVal( void ) const;

	private:

		static int const	_fractionalBits;
		int					_fixedPointVal;
};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif
