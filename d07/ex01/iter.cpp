#include <iostream>

template<typename T>
void	iter( T *arr, int size, void (*func)(T *arr, int size) ) {

	func(arr, size);
}

template<typename T>
void	ft_memzeroset( T *arr, int size ) {

	while ( size-- )
		arr[size] = '\0';
}

int		main( void ) {

	int* arr = new int[10];
	::iter<int>(arr, 10, ft_memzeroset );
	for ( int i = 0; i < 10; ++i )
		std::cout << arr[i] << std::endl;
	return 0;
}
