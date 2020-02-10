#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human {

public:

	Brain const brain;

	Human( void );
	~Human( void );

	std::string	identify( void ) const;
	Brain		getBrain( void ) const;
};

#endif
