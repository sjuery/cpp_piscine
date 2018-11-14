#include "ClapTrap.hpp"

class NinjaTrap : public ClapTrap {
public:
	NinjaTrap (std::string name);
	NinjaTrap (NinjaTrap&);
	~NinjaTrap ();

	NinjaTrap& operator=(NinjaTrap&);
	void ninjaShoebox(const std::string&);
};
