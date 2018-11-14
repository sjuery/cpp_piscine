#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main() {
	srand(time(0));
	FragTrap fragtrap("FragTrap");

	fragtrap.vaulthunter_dot_exe("Theo");
	fragtrap.vaulthunter_dot_exe("Theo");
	fragtrap.vaulthunter_dot_exe("Theo");
	fragtrap.vaulthunter_dot_exe("Theo");
	fragtrap.vaulthunter_dot_exe("Theo");
	fragtrap.rangedAttack("Zeid");
	fragtrap.meleeAttack("Logan");
	fragtrap.takeDamage(100);
	fragtrap.beRepaired(200);
	fragtrap.takeDamage(200);

	ScavTrap scavtrap("ScavTrap");

	scavtrap.challengeNewcomer("Theo");
	scavtrap.challengeNewcomer("Theo");
	scavtrap.challengeNewcomer("Theo");
	scavtrap.rangedAttack("Zeid");
	scavtrap.meleeAttack("Logan");
	scavtrap.takeDamage(100);
	scavtrap.beRepaired(200);
	scavtrap.takeDamage(200);

	NinjaTrap ninjatrap("NinjaTrap");

	ninjatrap.ninjaShoebox("Theo");
	ninjatrap.ninjaShoebox("Theo");
	ninjatrap.ninjaShoebox("Theo");
	ninjatrap.ninjaShoebox("Theo");
	ninjatrap.ninjaShoebox("Theo");
	ninjatrap.rangedAttack("Zeid");
	ninjatrap.meleeAttack("Logan");
	ninjatrap.takeDamage(50);
	ninjatrap.beRepaired(200);
	ninjatrap.takeDamage(200);
	return 0;
}
