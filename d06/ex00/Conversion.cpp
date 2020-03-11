#include "Conversion.hpp"

Conversion::Conversion( void ) {

	this->_i = 0;
	return;
}

Conversion::Conversion( Conversion const & src ) {

	*this = src;
}

Conversion &	Conversion::operator=( Conversion const & rhs ) {

	if ( this != &rhs ) {

		this->setInt( rhs.getInt() );
	}

	return *this;
}

Conversion::~Conversion( void ) {

	return;
}

int		Conversion::getInt( void ) const {

	return this->_i;
}

void	Conversion::setInt( int value ) {

	this->_i = value;
}

void	Conversion::convertToChar( double value ) {

	try {

		std::cout << "char: ";
		if ( std::isnan(value) || std::isinf(value) )
			throw Conversion::ImpossibleException();
		else if ( !isprint(value) )
			throw Conversion::NonDisplayableException();
		std::cout << static_cast<char> (value) << std::endl;
	}
	catch ( std::exception & e ) {

		std::cerr << e.what() << std::endl;
	}
}

void	Conversion::convertToInt( double value ) {

	try {

		std::cout << "int: ";
		if ( std::isnan(value) || std::isinf(value) 
			|| value > INT_MAX || value < INT_MIN )
			throw Conversion::ImpossibleException();
		this->setInt( static_cast<int> (value) );
		std::cout << this->getInt() << std::endl;
	}
	catch ( std::exception & e ) {

		std::cerr << e.what() << std::endl;
	}
}

void	Conversion::convertToFloat( double value ) {

	std::cout << "float: " << (static_cast<float> (value));
	if ( this->getInt() == (static_cast<float> (value)) )
		std::cout << ".0";
	std::cout << 'f' << std::endl;
}

void	Conversion::convertToDouble( double value ) {

	std::cout << "double: " << value;
	if ( value == this->getInt() )
		std::cout << ".0";
	std::cout << std::endl;
}

Conversion::NonDisplayableException::NonDisplayableException( void ) {

	return;
}

Conversion::NonDisplayableException::NonDisplayableException( Conversion::NonDisplayableException const & src ) {

	*this = src;
}

Conversion::NonDisplayableException &	Conversion::NonDisplayableException::operator=( Conversion::NonDisplayableException const & rhs ) {

	static_cast<void> ( rhs );
	return *this;
}

Conversion::NonDisplayableException::~NonDisplayableException( void ) throw() {

	return;
}

const char* Conversion::NonDisplayableException::what( void ) const throw() {

	return "Non displayable";
}

Conversion::ImpossibleException::ImpossibleException( void ) {

	return;
}

Conversion::ImpossibleException::ImpossibleException( Conversion::ImpossibleException const & src ) {

	*this = src;
}

Conversion::ImpossibleException &	Conversion::ImpossibleException::operator=( Conversion::ImpossibleException const & rhs ) {

	static_cast<void> ( rhs );
	return *this;
}

Conversion::ImpossibleException::~ImpossibleException( void ) throw() {

	return;
}

const char* Conversion::ImpossibleException::what( void ) const throw() {

	return "impossible";
}
