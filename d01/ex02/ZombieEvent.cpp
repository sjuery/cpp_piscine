#include "ZombieEvent.hpp"

void ZombieEvent::setZombieType(std::string givenType)
{
	type = givenType;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name, type);
	return zombie;
}

Zombie* ZombieEvent::randomChump()
{
	std::string names[10] = { "Inez", "Carlman", "Merlyn", "Morana", "Evelina",
								"Abdias", "John", "Zeid", "Bob", "Random" };

	Zombie *randomZombie = new Zombie(names[rand()%10], type);
	return randomZombie;
}
