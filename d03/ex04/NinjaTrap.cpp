#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap () {
	_maxHP = 60;
	_hitPoints = _maxHP;
	_maxEP = 120;
	_energyPoints = _maxEP;
	_level = 1;
	_meleeDMG = 60;
	_rangedDMG = 5;
	_armorRD = 0;
}

NinjaTrap::NinjaTrap (std::string name) {
	_name = name;
	_type = "9NJA";
	_maxHP = 60;
	_hitPoints = _maxHP;
	_maxEP = 120;
	_energyPoints = _maxEP;
	_level = 1;
	_meleeDMG = 60;
	_rangedDMG = 5;
	_armorRD = 0;
	std::cout << "9NJA-TP: At your service sir?" << std::endl;
}

NinjaTrap::NinjaTrap (NinjaTrap& src) {
	*this = src;
	std::cout << "FR4G-TP: Is he... me?" << std::endl;
}

NinjaTrap& NinjaTrap::operator=(NinjaTrap& src) {
	_name = src._name;
	_hitPoints = src._maxHP;
	_energyPoints = src._maxEP;
	_level = src._level;
	_meleeDMG = src._meleeDMG;
	_rangedDMG = src._rangedDMG;
	_armorRD = src._armorRD;
    return (*this);
}

NinjaTrap::~NinjaTrap () {
	std::cout << _type << "-TP: I am one, with the shadows!" << std::endl;
}

void NinjaTrap::ninjaShoebox(const std::string& target) {
	if(_energyPoints - 25 >= 0)
	{
		std::cout << _type << "-TP " << _name << " offers " << target << " some shoes..." << std::endl;
		std::cout << "Its super effective"  << "Ninja now has +2 armor!" << std::endl;
		_armorRD += 2;
		_energyPoints -= 25;
	}
	else
		std::cout << _type << "-TP " << _name << " only has " << _energyPoints << " Energy Points..." << std::endl;
}
