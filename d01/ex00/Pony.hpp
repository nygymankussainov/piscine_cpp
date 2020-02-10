#ifndef PONY_HPP
# define PONY_HPP

# include <string>

class Pony {

public:

	int			weight;
	int			height;
	std::string	name;
	std::string	color;

	Pony( void );
	~Pony( void );

	void	setParams(int weight, int height);
	void	setName(std::string name);
	void	setColor(std::string color);
};

#endif
