#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"
# include <iostream>

class AssaultTerminator : public ISpaceMarine {

	public:
		AssaultTerminator( void );
		AssaultTerminator( AssaultTerminator const & src );
		AssaultTerminator &	operator=( AssaultTerminator const & rhs );
		virtual ~AssaultTerminator( void );

		virtual ISpaceMarine*	clone( void ) const;
		virtual void	battleCry( void ) const;
		virtual void	rangedAttack( void ) const;
		virtual void	meleeAttack( void ) const;
};

#endif
