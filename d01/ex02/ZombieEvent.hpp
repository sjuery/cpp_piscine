#include <iostream>
#include <string>
#include "Zombie.hpp"

class ZombieEvent
{
	std::string type;
public:
	void setZombieType(std::string type);
	Zombie* newZombie(std::string name);
	Zombie* randomChump();
};
