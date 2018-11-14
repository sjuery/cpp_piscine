#include <iostream>
#include <sstream>
#include <string>

class Weapon {
    std::string _type;
public:
    Weapon(std::string type);

	std::string& getType();
	void setType(std::string new_type);
};
