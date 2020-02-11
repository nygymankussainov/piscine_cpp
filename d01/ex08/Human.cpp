#include "Human.hpp"

Human::Human( void ) {

	return;
}

Human::~Human( void ) {

	return;
}

void	Human::meleeAttack(std::string const & target) {

	std::cout << "Melee human attacks " + target << "\n";
}

void	Human::rangedAttack(std::string const & target) {

	std::cout << "Range human attacks " + target << "\n";
}

void	Human::intimidatingShout(std::string const & target) {

	std::cout << "Human shouts at " + target << "\n";
}

void	Human::action(std::string const & action_name, std::string const & target) {

	void	(Human::*funcptr[3])(std::string const & target) = { &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout };
	std::string actions[3] = { "meleeAttack", "rangedAttack", "intimidatingShout" };
	for (int i = 0; i < 3; ++i) {

		if (action_name == actions[i])
			(this->*(funcptr[i]))(target);
	}
}
