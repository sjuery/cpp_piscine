#include "ClapTrap.hpp"

class NinjaTrap : public virtual ClapTrap {
public:
	NinjaTrap ();
	NinjaTrap (std::string name);
	NinjaTrap (NinjaTrap&);
	~NinjaTrap ();

	NinjaTrap& operator=(NinjaTrap&);
	void ninjaShoebox(const std::string&);
};
