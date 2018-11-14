#include "ZombieHorde.hpp"

Zombie::Zombie()
{
	std::string names[10] = { "Inez", "Carlman", "Merlyn", "Morana", "Evelina",
								"Abdias", "John", "Zeid", "Bob", "Random" };
	std::string types[10] = { "Warrior", "Sniper", "Assassin", "Pirate", "CP:0",
								"Idiot", "Programmer", "Gamer", "Priest", "Dude" };
	_type = types[rand()%10];
	_name = names[rand()%10];
	std::cout << "<" << _name << " - (" << "Human" << ")>: " << " was turned into a Zombie!" << std::endl;
}

Zombie::~Zombie()
{
   std::cout << "<" << _name << " - (" << _type << ")>: " << "Turned back into a Human (Or died, we don't know)..." << std::endl;
}

void Zombie::announce(Zombie *zombie)
{
	std::cout << "<" << zombie->_name << " - (" << zombie->_type << ")>: " << "Braiiiiiiinnnssss... Pleaaaaaaassseeeee..." << std::endl;
}
