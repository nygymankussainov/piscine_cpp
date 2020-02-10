#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"

class ZombieEvent {

public:

	std::string type;
	std::string name;

	ZombieEvent( void );
	~ZombieEvent( void );

	void	setZombieType(std::string type);
	Zombie*	newZombie(std::string name);
	Zombie* randomChump( void );
};

#endif
