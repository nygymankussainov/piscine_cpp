#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int N ) {

	if (N <= 0)
	{
		this->horde = NULL;
		return;
	}
	this->horde = new Zombie[N];
	srand(time(NULL));
	for (int i = 0; i < N; ++i) {
		std::string name = this->randomName();
		this->horde[i].name = name;
		this->horde[i].type = "horde";
		this->horde[i].announce();
	}
	return;
}

ZombieHorde::~ZombieHorde( void ) {

	if (this->horde != NULL)
		delete [] this->horde;
	return;
}

std::string	ZombieHorde::randomName( void ) {

	std::string names[5] = {"Lesha", "Rashid", "Eltac", "Nygyman", "Vlad"};
	int r = rand() % 5;
	return (names[r]);
}
