#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

public:

	Weapon *weapon;
	std::string name;

	HumanB( std::string name );
	~HumanB( void );

	void	setWeapon(Weapon& weapon);
	void	attack( void );
};

#endif
