#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main( void ) {

	Zombie zombie;
	ZombieEvent zombEvent;

	zombie.name = "johny";
	zombie.type = "stinky";
	zombie.announce();

	zombEvent.type = "dumb";
	Zombie *newZomb = zombEvent.newZombie("Iles");
	delete newZomb;
	zombEvent.type = "retard";
	Zombie* randomZombie = zombEvent.randomChump();
	delete randomZombie;
	return 0;
}
