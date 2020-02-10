#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

public:

	std::string type;
	std::string name;

	Zombie( void );
	~Zombie( void );

	void	announce( void ) const;
};

#endif
