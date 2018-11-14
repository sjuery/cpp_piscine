#include "FragTrap.hpp"

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
	return 0;
}
