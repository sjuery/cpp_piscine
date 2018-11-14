#include <iostream>

class FragTrap {
private:
	std::string _name;
	int _hitPoints;
	static const int _maxHP = 100;
	int _energyPoints;
	static const int _maxEP = 100;
	int _level;
	int _meleeDMG;
	int _rangedDMG;
	int _armorRD;

public:
	FragTrap (std::string name);
	FragTrap (FragTrap&);
	~FragTrap ();

	FragTrap& operator=(FragTrap&);
	void vaulthunter_dot_exe(const std::string&);
	void rangedAttack(const std::string&);
	void meleeAttack(const std::string&);
	void beRepaired(unsigned int);
	void takeDamage(unsigned int);
};
