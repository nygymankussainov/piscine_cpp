#include "Span.hpp"

Span::Span( void ) {

	this->N = 0;
	this->index = 0;
	return;
}

Span::Span( unsigned int N ) {

	this->N = N;
	this->index = 0;
	this->v.resize( N );
	return;
}

Span::Span( Span const & src ) {

	*this = src;
}

Span &	Span::operator=( Span const & rhs ) {

	if ( this != &rhs ) {

		this->v = rhs.getV();
		this->N = rhs.getN();
	}

	return *this;
}

Span::~Span( void ) {

	return;
}

unsigned int	Span::getN( void ) const {

	return this->N;
}

std::vector<int> Span::getV( void ) const {

	return this->v;
}

void	Span::addNumber( int value ) {

	try {

		this->v.at( this->index ) = value;
		++this->index;
	}
	catch( std::out_of_range & oor ) {

		std::cerr << "Out of range error: " << oor.what() << std::endl;
	}
}

int		Span::shortestSpan( void ) {

	if ( this->v.size() == 0 )
		return 0;
	std::sort( this->v.begin(), this->v.end(), std::greater<int>() );
	int diff = INT_MAX;

	std::vector<int>::iterator it = this->v.begin();
	while ( it + 1 != this->v.end() ) {

		if ( *it - *(it + 1) < diff )
			diff = *it - *(it + 1);
		++it;
	}

	return diff;
}

int		Span::longestSpan( void ) {

	if ( this->v.size() == 0 )
		return 0;
	std::vector<int>::iterator max = std::max_element( this->v.begin(), this->v.end() );
	std::vector<int>::iterator min = std::min_element( this->v.begin(), this->v.end() );
	return *max - *min;
}
