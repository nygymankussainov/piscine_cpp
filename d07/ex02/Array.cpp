#include "Array.hpp"

template<typename T>
Array<T>::Array( void ) {

	this->_size = 0;
	this->_arr = NULL;
	return;
}

template<typename T>
Array<T>::Array( unsigned int n ) {

	this->_arr = new T[n];
	return;
}

template<typename T>
Array<T>::Array( Array const & src ) {

	*this = src;
}

template<typename T>
Array<T> &	Array<T>::operator=( Array const & rhs ) {

	if ( this != &rhs ) {

		delete[] this->getArr();
		this->getArr() = new T[rhs.length()];
		this->_size = rhs.length();
		for ( int i = 0; i < rhs.length(); ++i ) {

			this[i] = rhs[i];
		}
	}

	return *this;
}

template<typename T>
Array<T>::~Array( void ) {

	return;
}

template<typename T>
unsigned int	Array<T>::length( void ) const {

	return this->_size;
}

template<typename T>
T*	Array<T>::getArr( void ) const {

	return this->_arr;
}

template<typename T>
T&	Array<T>::operator[]( unsigned int i ) {

	try {

		if ( i >= this->length() )
			throw Array<T>::OutOfBoundsException();
	}
	catch ( std::exception & e ) {

		std::cerr << e.what() << std::endl;
	}
	return this->_arr[i];
}

template<typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException( void ) {
	
	return;
}

template<typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException( OutOfBoundsException const & src ) {

	*this = src;
}

template<typename T>
typename Array<T>::OutOfBoundsException &	Array<T>::OutOfBoundsException::operator=( OutOfBoundsException const & rhs ) {

	static_cast<void> ( rhs );
	return *this;
}

template<typename T>
Array<T>::OutOfBoundsException::~OutOfBoundsException( void ) throw() {

	return;
}

template<typename T>
const char*	Array<T>::OutOfBoundsException::what( void ) const throw() {

	return "Trying to access element out of bounds of the array";
}

template<typename T>
std::ostream &	operator<<( std::ostream & o, const Array<T>& arr ) {

	for ( int i = 0; i < arr.length(); ++i )
		o << arr[i];
	return o;
}
