#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy {

	protected:

		std::string _type;
		int	_hp;

	public:

		Enemy( void );
		Enemy( int hp, std::string const & type );
		Enemy( Enemy const & src );
		virtual ~Enemy( void );

		Enemy &	operator=( Enemy const & rhs );
		std::string const getType( void ) const;
		int	getHP( void ) const;

		virtual void	takeDamage( int );
};

#endif
