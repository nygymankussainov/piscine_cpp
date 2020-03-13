#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>

class Span {

	private:
		unsigned int	N;
		std::vector<int> v;
		int				index;

	public:
		Span( void );
		Span( unsigned int N );
		Span( Span const & src );
		Span &	operator=( Span const & rhs );
		~Span( void );

		unsigned int	getN( void ) const;
		std::vector<int> getV( void ) const;
		void	addNumber( int value );
		int		shortestSpan( void );
		int		longestSpan( void );
};

#endif
