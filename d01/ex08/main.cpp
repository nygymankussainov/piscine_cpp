#include "Human.hpp"

int		main( void ) {

	Human human;

	human.action("meleeAttack", "Alien");
	human.action("rangedAttack", "Goat");
	human.action("intimidatingShout", "Bear");
	return 0;
}
