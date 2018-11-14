#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(Fixed& src) {
	std::cout << "Assignation operator called" << std::endl;
	setRawBits(src.getRawBits());
    return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}
