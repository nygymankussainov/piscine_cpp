#include <iostream>
#include <fstream>

int		main(int argc, char **argv) {

	if ( argc > 1 ) {
		int i = 1;
		while (i < argc) {
			std::ifstream file(argv[i]);
			if (file.is_open())
				std::cout << file.rdbuf();
			++i;
		}
	}
	else {
		while (true) {
			std::string s;
			std::cin >> s;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				return 0;
			}
			std::cout << s << "\n";
		}
	}
	return 0;
}
