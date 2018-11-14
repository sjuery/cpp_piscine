#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap {
public:
	SuperTrap (std::string name);
	SuperTrap (SuperTrap&);
	~SuperTrap ();

	SuperTrap& operator=(SuperTrap&);
};
