#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int src) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(src << _fractBits);
}

Fixed::Fixed(float src) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(src * (1 << _fractBits)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& src) {
    stream << src.toFloat();
    return (stream);
}

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Assignation operator called" << std::endl;
    setRawBits(src._value);
    return (*this);
}

int   Fixed::getRawBits() {
	return (_value);
}

void  Fixed::setRawBits(const int newValue) {
	_value = newValue;
}

int   Fixed::toInt() const {
	return(_value >> _fractBits);
}

float Fixed::toFloat() const {
	return (static_cast<float>(_value) / (1U << _fractBits));
}
