#include "HumanA.hpp"
#include "HumanB.hpp"

int		main( void ) {

	{
		Weapon club = Weapon("test");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("test2");
		bob.attack();
	}

	{
		Weapon club = Weapon("test3");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("test4");
		jim.attack();
	}
	return 0;
}
