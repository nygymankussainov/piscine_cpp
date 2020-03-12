#include "Array.hpp"

int		main( void ) {

	Array<int> arr( 10 );

	for ( int i = 0; i < arr.length(); ++i )
		arr[i] = 12;
	for ( int i = 0; i < arr.length(); ++i ) {

		std::cout << arr[i] << std::endl;
	}
	return 0;
}
