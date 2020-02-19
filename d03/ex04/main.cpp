#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int		main( void ) {

	SuperTrap super("Super");
	SuperTrap super1 = super;

	std::cout << super.getName() << std::endl;
	std::cout << super1.getName() << std::endl;
	std::cout << super.getHP() << std::endl;
	std::cout << super1.getHP() << std::endl;
	std::cout << super.getEP() << std::endl;
	std::cout << super1.getEP() << std::endl;

	return 0;
}
