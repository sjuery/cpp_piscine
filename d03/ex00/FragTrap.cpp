#include "FragTrap.hpp"

FragTrap::FragTrap (std::string name) :
_name(name), _hitPoints(_maxHP), _energyPoints(_maxEP), _level(1),
_meleeDMG(30), _rangedDMG(20), _armorRD(5) {
	std::cout << "FR4G-TP: Who -- uh, me sir?" << std::endl;
}

FragTrap::FragTrap (FragTrap& src) {
	*this = src;
	std::cout << "FR4G-TP: Is he... me?" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& src) {
	_name = src._name;
	_hitPoints = src._maxHP;
	_energyPoints = src._maxEP;
	_level = src._level;
	_meleeDMG = src._meleeDMG;
	_rangedDMG = src._rangedDMG;
	_armorRD = src._armorRD;
    return (*this);
}

FragTrap::~FragTrap () {
	std::cout << "FR4G-TP: I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(const std::string& target) {
	if(_energyPoints - 25 >= 0)
	{
		int i = rand()%5;
		std::string names[5] = { "Reverse Eruption", "Majestic Instant Stomp", "Giant Bee, Cutting Shatter", "Parasitic Goat, Shocking Spell", "Winter Moose Eating Cat" };
		int damage[5] = { 45, 2, 7, 1000000, 0 };
		std::cout << "FR4G-TP " << _name << " attacks " << target << " using " << names[i] << " and dealing " << damage[i] << " points of damage." << std::endl;
		_energyPoints -= 25;
	}
	else
		std::cout << "FR4G-TP " << _name << " only has " << _energyPoints << " Energy Points..." << std::endl;
}

void FragTrap::rangedAttack(const std::string& target) {
	std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << _rangedDMG << " points of damage." << std::endl;
}

void FragTrap::meleeAttack(const std::string& target) {
	std::cout << "FR4G-TP " << _name << " attacks " << target << " in close combat, causing " << _meleeDMG << " points of damage." << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	if((int)(amount - _armorRD) < 0)
		amount = 0;
	else
		amount -= _armorRD;
	if((_hitPoints - (int)amount) < 0)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "FR4G-TP " << _name << " took " << amount << " points of damage and now has " << _hitPoints << " health points." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if((_hitPoints + amount) > _maxHP)
		_hitPoints = _maxHP;
	else
		_hitPoints += amount;
	std::cout << "FR4G-TP " << _name << " was repaired by " << amount << " health points and now has " << _hitPoints << " health points." << std::endl;
}
