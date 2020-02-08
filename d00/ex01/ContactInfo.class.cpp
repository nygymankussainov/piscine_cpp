#include <iostream>
#include <iomanip>
#include "ContactInfo.class.hpp"
#include "phonebook.hpp"

ContactInfo::ContactInfo( void ) {

	return;
}

ContactInfo::~ContactInfo( void ) {

	return;
}

void	ContactInfo::setInfo() {

	std::cout << "First name: ";
	std::cin >> this->firstName;
	std::cout << "Last name: ";
	std::cin >> this->lastName;
	std::cout << "Nickname: ";
	std::cin >> this->nickname;
	std::cout << "Login: ";
	std::cin >> this->login;
	std::cout << "Postal address: ";
	std::cin >> this->postalAddress;
	std::cout << "Email address: ";
	std::cin >> this->email;
	std::cout << "Phone number: ";
	std::cin >> this->phone;
	std::cout << "Birthday date: ";
	std::cin >> this->birthday;
	std::cout << "Favourite meal: ";
	std::cin >> this->favMeal;
	std::cout << "Underwear color: ";
	std::cin >> this->underwearColor;
	std::cout << "Darkest secret: ";
	std::cin >> this->darkestSecret;
}

void	ContactInfo::getInfo() const {

	std::cout << std::left << std::setw(17); 
	std::cout << "First name:" << this->firstName << "\n";
	std::cout << std::left << std::setw(17); 
	std::cout << "Last name:" << this->lastName << "\n";
	std::cout << std::left << std::setw(17); 
	std::cout << "Nickname:" << this->nickname << "\n";
	std::cout << std::left << std::setw(17); 
	std::cout << "Login:" << this->login << "\n";
	std::cout << std::left << std::setw(17); 
	std::cout << "Postal address:" << this->postalAddress << "\n";
	std::cout << std::left << std::setw(17); 
	std::cout << "Email:" << this->email << "\n";
	std::cout << std::left << std::setw(17); 
	std::cout << "Phone number:" << this->phone << "\n";
	std::cout << std::left << std::setw(17); 
	std::cout << "Birthday date:" << this->birthday << "\n";
	std::cout << std::left << std::setw(17); 
	std::cout << "Favourite meal:" << this->favMeal << "\n";
	std::cout << std::left << std::setw(17); 
	std::cout << "Underwear color:" << this->underwearColor << "\n";
	std::cout << std::left << std::setw(17); 
	std::cout << "Darkest secret:" << this->darkestSecret << "\n";
}
