#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	return 0;
}
