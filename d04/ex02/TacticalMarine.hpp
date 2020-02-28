#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"
# include <iostream>

class TacticalMarine : public ISpaceMarine {

	public:
		TacticalMarine( void );
		TacticalMarine( TacticalMarine const & src );
		TacticalMarine &	operator=( TacticalMarine const & rhs );
		virtual ~TacticalMarine( void );

		virtual ISpaceMarine*	clone( void ) const;
		virtual void	battleCry( void ) const;
		virtual void	rangedAttack( void ) const;
		virtual void	meleeAttack( void ) const;
};

#endif
