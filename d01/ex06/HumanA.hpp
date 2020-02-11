#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {

public:

	std::string name;
	Weapon *weapon;

	HumanA( std::string name, Weapon& weaponType );
	~HumanA( void );

	void	attack( void );
};

#endif
