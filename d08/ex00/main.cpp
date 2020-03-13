#include "easyfind.hpp"

template<typename T>
void	easyfind( T container, int value ) {

	if ( std::find( container.begin(), container.end(), value ) != container.end() )
		std::cout << "The value " << value << " is found" << std::endl;
	else
		std::cout << "The value " << value << " is not found" << std::endl;
}

int		main( void ) {

	std::vector<int> v;

	for ( int i = 0; i < 10; ++i )
		v.push_back( i );

	easyfind< std::vector<int> >(v, 10);
	return 0;
}
