#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	setType(type);
}

std::string& Weapon::getType(void) {
	return(_type);
}

void Weapon::setType(std::string new_type) {
	_type = new_type;
}
