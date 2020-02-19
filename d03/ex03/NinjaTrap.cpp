#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <ctime>

NinjaTrap::NinjaTrap( void ) {

	std::cout << "class NinjaTrap default constructor is called" << std::endl;
	return;
}

NinjaTrap::NinjaTrap( std::string name ) {

	std::cout << "class NinjaTrap parameterized constructor is called" << std::endl;
	ClapTrap::setAttributes( name, 60, 60, 120, 120, 1, 60, 5, 0 );
	return;
}

NinjaTrap::~NinjaTrap ( void ) {

	std::cout << "class NinjaTrap default destructor is called" << std::endl;
	return;
}

void	NinjaTrap::ninjaShoebox( FragTrap const & ft  ) {

	std::cout << "Ninja " << this->_name << " attacks FragTrap " << ft.getName() << ":) ! he-he lol" << std::endl;

}

void	NinjaTrap::ninjaShoebox( ScavTrap const & st  ) {

	std::cout << "Ninja " << this->_name << " attacks ScavTrap :) " << st.getName() <<  " ! he-he kek" << std::endl;

}

void	NinjaTrap::ninjaShoebox( NinjaTrap const & nt  ) {

	std::cout << "Ninja " << this->_name << " attacks NinjaTrap :) " << nt.getName() << " ! he" << std::endl;

}
