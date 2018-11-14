#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
	ScavTrap (std::string name);
	ScavTrap (ScavTrap&);
	~ScavTrap ();

	ScavTrap& operator=(ScavTrap&);
	void challengeNewcomer(const std::string&);
};
