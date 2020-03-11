#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <stdexcept>
# include <cmath>

class Conversion {

	private:
		int		_i;

	public:
		Conversion( void );
		Conversion( Conversion const & src );
		Conversion &	operator=( Conversion const & rhs );
		~Conversion( void );

		void	convertToChar( double value );
		void	convertToInt( double value );
		void	convertToFloat( double value );
		void	convertToDouble( double value );

		int		getInt( void ) const;
		void	setInt( int value );

		class NonDisplayableException : public std::exception {

			public:
				NonDisplayableException( void );
				NonDisplayableException( NonDisplayableException const & src );
				NonDisplayableException &	operator=( NonDisplayableException const & rhs );
				virtual ~NonDisplayableException( void ) throw();

				virtual const char*	what( void ) const throw();
		};

		class ImpossibleException : public std::exception {

			public:
				ImpossibleException( void );
				ImpossibleException( ImpossibleException const & src );
				ImpossibleException &	operator=( ImpossibleException const & rhs );
				virtual ~ImpossibleException( void ) throw();

				virtual const char*	what( void ) const throw();
		};
};

#endif
