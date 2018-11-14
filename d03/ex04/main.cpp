#include "ScavTrap.hpp"
#include "SuperTrap.hpp"

int main() {
	srand(time(0));
	std::cout << "FragTrap Example:" << std::endl;
	FragTrap* fragtrap = new FragTrap("FragTrap");

	fragtrap->vaulthunter_dot_exe("Theo");
	fragtrap->vaulthunter_dot_exe("Theo");
	fragtrap->vaulthunter_dot_exe("Theo");
	fragtrap->vaulthunter_dot_exe("Theo");
	fragtrap->vaulthunter_dot_exe("Theo");
	fragtrap->rangedAttack("Zeid");
	fragtrap->meleeAttack("Logan");
	fragtrap->takeDamage(100);
	fragtrap->beRepaired(200);
	fragtrap->takeDamage(200);
	delete fragtrap;

	std::cout << "\nScavTrap Example:" << std::endl;
	ScavTrap* scavtrap = new ScavTrap("ScavTrap");

	scavtrap->challengeNewcomer("Theo");
	scavtrap->challengeNewcomer("Theo");
	scavtrap->challengeNewcomer("Theo");
	scavtrap->rangedAttack("Zeid");
	scavtrap->meleeAttack("Logan");
	scavtrap->takeDamage(100);
	scavtrap->beRepaired(200);
	scavtrap->takeDamage(200);
	delete scavtrap;

	std::cout << "\nNinjaTrap Example:" << std::endl;
	NinjaTrap* ninjatrap = new NinjaTrap("NinjaTrap");

	ninjatrap->ninjaShoebox("Theo");
	ninjatrap->ninjaShoebox("Theo");
	ninjatrap->ninjaShoebox("Theo");
	ninjatrap->ninjaShoebox("Theo");
	ninjatrap->ninjaShoebox("Theo");
	ninjatrap->rangedAttack("Zeid");
	ninjatrap->meleeAttack("Logan");
	ninjatrap->takeDamage(50);
	ninjatrap->beRepaired(200);
	ninjatrap->takeDamage(200);
	delete ninjatrap;

	std::cout << "\nSuperTrap Example:" << std::endl;
	SuperTrap* supertrap = new SuperTrap("SuperTrap");

	supertrap->vaulthunter_dot_exe("Theo");
	supertrap->ninjaShoebox("Theo");
	supertrap->vaulthunter_dot_exe("Theo");
	supertrap->ninjaShoebox("Theo");
	supertrap->vaulthunter_dot_exe("Theo");
	supertrap->rangedAttack("Zeid");
	supertrap->meleeAttack("Logan");
	supertrap->takeDamage(50);
	supertrap->beRepaired(200);
	supertrap->takeDamage(200);
	delete supertrap;
	return 0;
}
