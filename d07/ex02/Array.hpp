#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template<typename T>
class Array {

	private:
		T*	_arr;
		unsigned int	_size;

	public:
		Array( void ) {

			this->_size = 0;
			this->_arr = NULL;
			return;
		}

		Array( unsigned int n ) {
			
			this->_arr = new T[n];
			return;
		}

		Array( const Array <T>& src ) {

			*this = src;
		}
		Array <T>&	operator=( const Array <T>& rhs ) {

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
		~Array( void ) { return; }

		T&	operator[]( unsigned int i ) {

			if ( i >= static_cast<unsigned int> (this->length()) )
				throw std::exception();
			return this->_arr[i];
		}
		int	length( void ) const {

			return this->_size;
		}
		T*	getArr( void ) const { 

			return this->_arr;
		}
};

#endif
