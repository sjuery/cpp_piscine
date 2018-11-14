#include "ScavTrap.hpp"

ScavTrap::ScavTrap (std::string name) {
	_name = name;
	_type = "SC5V";
	_maxHP = 100;
	_hitPoints = _maxHP;
	_maxEP = 50;
	_energyPoints = _maxEP;
	_level = 1;
	_meleeDMG = 20;
	_rangedDMG = 15;
	_armorRD = 3;
	std::cout << "SC5V-TP: Who -- am I?" << std::endl;
}

ScavTrap::ScavTrap (ScavTrap& src) {
	*this = src;
	std::cout << "FR4G-TP: Is he... me?" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& src) {
	_name = src._name;
	_hitPoints = src._maxHP;
	_energyPoints = src._maxEP;
	_level = src._level;
	_meleeDMG = src._meleeDMG;
	_rangedDMG = src._rangedDMG;
	_armorRD = src._armorRD;
    return (*this);
}

ScavTrap::~ScavTrap () {
	std::cout << "SC5V-TP: What is this... light..." << std::endl;
}

void ScavTrap::challengeNewcomer(const std::string& target) {
	if(_energyPoints - 25 >= 0)
	{
		int i = rand()%5;
		std::string challenge[5] = { "reproduce FdF (No leaks allowed)", "a Starving Contest", "a Complex Calculation Race", "not have a heart beat", "to find the lair's password" };
		int probability[5] = { 0, 0, 0, 0, 0 };
		std::cout << "SC5V-TP " << _name << " challenged " << target << " to " << challenge[i] << " which gives his human opponent a " << 0 << "% chance of succeeding." << std::endl;
		_energyPoints -= 25;
	}
	else
		std::cout << "SC5V-TP " << _name << " only has " << _energyPoints << " Energy Points..." << std::endl;
}
