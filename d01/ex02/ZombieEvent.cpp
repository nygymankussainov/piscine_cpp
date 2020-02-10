#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent( void ) {

	return;
}

ZombieEvent::~ZombieEvent( void ) {

	return;
}

void	ZombieEvent::setZombieType(std::string type) {

	this->type = type;
}

Zombie*	ZombieEvent::newZombie(std::string name) {

	Zombie* newZomb = new Zombie;
	newZomb->name = name;
	newZomb->type = this->type;
	newZomb->announce();
	return newZomb;
}

Zombie* ZombieEvent::randomChump( void ) {

	std::string names[5] = {"Lesha", "Rashid", "Eltac", "Nygyman", "Vlad"};
    srand(time(NULL));
	int i = rand() % 5;
	Zombie* newZomb = this->newZombie(names[i]);
	return newZomb;
}
