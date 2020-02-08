#include <iostream>
#include <iomanip>
#include "ContactInfo.class.hpp"

void	print_table(ContactInfo *contacts, int contactsNumber) {

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|\n";
	for (int i = 0; i < contactsNumber; ++i) {
		std::cout << std::setw(10) << i + 1 << "|";
		if (contacts[i].firstName.length() > 10) {
			std::cout << std::setw(10) << contacts[i].firstName.substr(0, 9) + ".|";
		}
		else
			std::cout << std::setw(10) << contacts[i].firstName << "|";
		if (contacts[i].lastName.length() > 10) {
			std::cout << std::setw(10) << contacts[i].lastName.substr(0, 9) + ".|";
		}
		else
			std::cout << std::setw(10) << contacts[i].lastName << "|";
		if (contacts[i].nickname.length() > 10) {
			std::cout << std::setw(10) << contacts[i].nickname.substr(0, 9) + ".|";
		}
		else
			std::cout << std::setw(10) << contacts[i].nickname << "|";
		std::cout << "\n";
	}
}

void	search(ContactInfo *contacts, int contactsNumber) {

	print_table(contacts, contactsNumber);
	std::cout << "Type a contact number for details: ";
	int nb;
	std::cin >> nb;
	while (true) {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			return;
		}
		else if (nb > 0 && nb <= contactsNumber) {
			contacts[nb - 1].getInfo();
			return;
		}
		else
			std::cout << "Unavailable contact number.\n";
		std::cin >> nb;
	}
}

int		main(void)
{
	std::string command;
	ContactInfo	contacts[8];

	std::cout << "Type a command:\n";
	std::cin >> command;
	int i = 0;
	while (command != "EXIT")
	{
		if (command == "ADD") {
			if (i > 7) {
				std::cout << "Sorry, phonebook is full\n";
			}
			else {
				contacts[i].setInfo();
				++i;
			}
		}
		else if (command == "SEARCH") {
			if (i == 0)
				std::cout << "Phonebook is empty\n";
			else
				search(contacts, i);
		}
		else {
			std::cout << "Invalid command\n";
		}
		std::cin >> command;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "You killed my program dumbass!\n";
			return (0);
		}
	}
	return (0);
}
