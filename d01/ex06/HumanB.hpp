#include "Weapon.hpp"

class HumanB {
	std::string _name;
    Weapon* _weapon;
	static Weapon _tmp;
public:
    HumanB(std::string name, Weapon& = _tmp);

	void setWeapon(Weapon& new_weapon);
    void attack();
};
