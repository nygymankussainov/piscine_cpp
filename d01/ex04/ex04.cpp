#include <iostream>

int		main( void ) {

	std::string str("HI THIS IS BRAIN");
	std::string* ptr = &str;
	std::string& ref = str;

	std::cout << str << "\n";
	std::cout << *ptr << "\n";
	std::cout << ref << "\n";
	return 0;
}
