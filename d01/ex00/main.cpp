#include <iostream>
#include <string>
#include "Pony.hpp"

Pony	*ponyOnTheHeap( void ) {

	Pony *newPony = new Pony;
	return newPony;
}

Pony	ponyOnTheStack( void ) {

	Pony newPony;
	return newPony;
}

int		main( void ) {

	Pony *ponyHeap = ponyOnTheHeap();
	Pony ponyStack = ponyOnTheStack();

	ponyHeap->setName("Heappie");
	ponyHeap->setColor("Blue");
	ponyHeap->setParams(50, 1);

	ponyStack.setName("Stackie");
	ponyStack.setColor("Yellow");
	ponyStack.setParams(34, 2);
	delete ponyHeap;
	return (0);
}
