#include "ZombieEvent.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
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
