#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {

public:

	int size;
	int weight;

	Brain( void );
	~Brain( void );

	std::string	identify( void );

private:

	std::string _address;
};

#endif
