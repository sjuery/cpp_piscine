#include "SuperTrap.hpp"

SuperTrap::SuperTrap (std::string name) {
	_name = name;
	_type = "S0PR";
	_maxHP = _maxHP;
	_hitPoints = _maxHP;
	_maxEP = _maxEP;
	_energyPoints = _maxEP;
	_level = 1;
	_meleeDMG = _meleeDMG;
	_rangedDMG = _rangedDMG;
	_armorRD = _armorRD;
	std::cout << "9NJA-TP: Who shall I annihilate in this lifetime?" << std::endl;
}

SuperTrap::SuperTrap (SuperTrap& src) {
	*this = src;
	std::cout << "FR4G-TP: Is he... me?" << std::endl;
}

SuperTrap& SuperTrap::operator=(SuperTrap& src) {
	_name = src._name;
	_maxHP = src._maxHP;
	_hitPoints = src._maxHP;
	_maxEP = src._maxEP;
	_energyPoints = src._maxEP;
	_level = src._level;
	_meleeDMG = src._meleeDMG;
	_rangedDMG = src._rangedDMG;
	_armorRD = src._armorRD;
    return (*this);
}

SuperTrap::~SuperTrap () {
	std::cout << _type << "-TP: Someone... Stronger than me... Impossible..." << std::endl;
}
