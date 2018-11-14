#include "Brain.hpp"

Brain::Brain() {
    _intellect = 10000000;
}

Brain::~Brain() {}

std::string Brain::identify() {
    std::stringstream adrsrep;
    adrsrep << this;
    return (adrsrep.str());
}
