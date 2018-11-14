#include "FragTrap.hpp"

FragTrap::FragTrap (std::string name) {
	_name = name;
	_type = "FR4G";
	_maxHP = 100;
	_hitPoints = _maxHP;
	_maxEP = 100;
	_energyPoints = _maxEP;
	_level = 1;
	_meleeDMG = 30;
	_rangedDMG = 20;
	_armorRD = 5;
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
		std::cout << _type << "-TP " << _name << " attacks " << target << " using " << names[i] << " and dealing " << damage[i] << " points of damage." << std::endl;
		_energyPoints -= 25;
	}
	else
		std::cout << _type << "-TP " << _name << " only has " << _energyPoints << " Energy Points..." << std::endl;
}
