#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde {

public:

	Zombie*	horde;
	std::string type;

	ZombieHorde( int N );
	~ZombieHorde( void );

	std::string randomName( void );

};

#endif
