#include <iostream>
#include <string>

class Zombie {
	std::string _name;
	std::string _type;
public:
	Zombie(void);
	~Zombie(void);
	static void announce(Zombie *zombie);
};
