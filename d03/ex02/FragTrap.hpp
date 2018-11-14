#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap (std::string name);
	FragTrap (FragTrap&);
	~FragTrap ();

	FragTrap& operator=(FragTrap&);
	void vaulthunter_dot_exe(const std::string&);
};
