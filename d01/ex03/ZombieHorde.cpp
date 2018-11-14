#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
	Zombie* horde = new Zombie[n];

	for(int i = 0; i < n; i++)
		Zombie::announce(horde+i);
	delete [] horde;
}
