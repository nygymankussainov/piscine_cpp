#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed {

	public:

		Fixed( void );
		Fixed( Fixed const & src ); // copy constructor
		~Fixed( void );

		Fixed &	operator=( Fixed const & rhs ); // operator overload
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:

		int					_fixedPointVal;
		static int const	_fractionalBits;

};

#endif
