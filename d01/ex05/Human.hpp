#include "Brain.hpp"

class Human {
    Brain _brain;
public:
    Human();
    ~Human();

    Brain& getBrain();

    std::string identify();
};
