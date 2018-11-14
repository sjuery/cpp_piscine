#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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

	srand(time(0));
	ScavTrap scavtrap("ScavTrap");

	scavtrap.challengeNewcomer("Theo");
	scavtrap.challengeNewcomer("Theo");
	scavtrap.challengeNewcomer("Theo");
	scavtrap.rangedAttack("Zeid");
	scavtrap.meleeAttack("Logan");
	scavtrap.takeDamage(100);
	scavtrap.beRepaired(200);
	scavtrap.takeDamage(200);
	return 0;
}
