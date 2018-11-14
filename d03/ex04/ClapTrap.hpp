#pragma once
#include <iostream>

class ClapTrap {
protected:
	std::string _name;
	std::string _type;
	int _hitPoints;
	int _maxHP;
	int _energyPoints;
	int _maxEP;
	int _level;
	int _meleeDMG;
	int _rangedDMG;
	int _armorRD;

public:
	ClapTrap ();
	ClapTrap (ClapTrap&);
	~ClapTrap ();

	ClapTrap& operator=(ClapTrap&);
	void rangedAttack(const std::string&);
	void meleeAttack(const std::string&);
	void beRepaired(unsigned int);
	void takeDamage(unsigned int);
};
