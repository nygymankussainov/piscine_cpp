#include <iostream>
#include <fstream>

void	check_cin( void ) {

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Invalid input\n";
		exit (0);
	}
}

void	replace(std::string filename, std::string s1, std::string s2) {

	std::ifstream file1(filename);
	std::ofstream file2(filename + ".replace");

	if (file1.is_open() == 0 || file2.is_open() == 0) {

		std::cout << "Couln't open a file\n";
		return;
	}
	std::string s;
	while (file1.eof() != 1)
	{
		getline(file1, s);
		while (s.find(s1) != std::string::npos)
		{
			s.replace(s.find(s1), s1.length(), s2);
		}
		file2 << s << "\n";
	}
}

int		main( void ) {

	std::string filename;
	std::string s1;
	std::string s2;

	std::cin >> filename;
	check_cin();
	std::cin >> s1;
	check_cin();
	std::cin >> s2;
	check_cin();
	replace(filename, s1, s2);
	return 0;
}
