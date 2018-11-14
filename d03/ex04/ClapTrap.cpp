#include "ClapTrap.hpp"

ClapTrap::ClapTrap () {
	std::cout << "UNKN-TP: What -- uh, am I sir?" << std::endl;
}

ClapTrap::ClapTrap (ClapTrap& src) {
	*this = src;
	std::cout << "FR4G-TP: Is he... me?" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap& src) {
	_name = src._name;
	_hitPoints = src._maxHP;
	_energyPoints = src._maxEP;
	_level = src._level;
	_meleeDMG = src._meleeDMG;
	_rangedDMG = src._rangedDMG;
	_armorRD = src._armorRD;
    return (*this);
}

ClapTrap::~ClapTrap () {
	std::cout << _type << "-TP: Did I serve you right?" << std::endl;
}

void ClapTrap::rangedAttack(const std::string& target) {
	std::cout << _type << "-TP " << _name << " attacks " << target << " at range, causing " << _rangedDMG << " points of damage." << std::endl;
}

void ClapTrap::meleeAttack(const std::string& target) {
	std::cout << _type << "-TP " << _name << " attacks " << target << " in close combat, causing " << _meleeDMG << " points of damage." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if((int)(amount - _armorRD) < 0)
		amount = 0;
	else
		amount -= _armorRD;
	if((_hitPoints - (int)amount) < 0)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << _type << "-TP " << _name << " took " << amount << " points of damage and now has " << _hitPoints << " health points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if((_hitPoints + amount) > _maxHP)
		_hitPoints = _maxHP;
	else
		_hitPoints += amount;
	std::cout << _type << "-TP " << _name << " was repaired by " << amount << " health points and now has " << _hitPoints << " health points." << std::endl;
}
