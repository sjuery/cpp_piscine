#include "HumanB.hpp"

Weapon HumanB::_tmp("fists");

HumanB::HumanB(std::string name, Weapon& weapon) : _name(name), _weapon(&weapon){}

void HumanB::setWeapon(Weapon& new_weapon) {
	_weapon = &new_weapon;
}

void HumanB::attack() {
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}
