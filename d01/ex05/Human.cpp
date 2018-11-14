#include "Human.hpp"

Human::Human() {
    _brain = Brain();
}

Human::~Human() {
    _brain.~Brain();
}

Brain& Human::getBrain() {
    return (_brain);
}

std::string Human::identify() {
    return (_brain.identify());
}
