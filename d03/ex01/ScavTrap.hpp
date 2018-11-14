#include <iostream>

class ScavTrap {
private:
	std::string _name;
	int _hitPoints;
	static const int _maxHP = 100;
	int _energyPoints;
	static const int _maxEP = 50;
	int _level;
	int _meleeDMG;
	int _rangedDMG;
	int _armorRD;

public:
	ScavTrap (std::string name);
	ScavTrap (ScavTrap&);
	~ScavTrap ();

	ScavTrap& operator=(ScavTrap&);
	void challengeNewcomer(const std::string&);
	void rangedAttack(const std::string&);
	void meleeAttack(const std::string&);
	void beRepaired(unsigned int);
	void takeDamage(unsigned int);
};
