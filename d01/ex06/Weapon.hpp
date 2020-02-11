#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {

public:

	std::string type;

	Weapon( std::string type );
	~Weapon( void );

	std::string const&	getType( void ) const;
	void				setType( std::string type );

};

#endif
