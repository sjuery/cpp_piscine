#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() {
	setRawBits(0);
}

Fixed::Fixed(const Fixed& src) {
	*this = src;
}

Fixed::Fixed(int src) {
	setRawBits(src << _fractBits);
}

Fixed::Fixed(float src) {
	setRawBits(roundf(src * (1 << _fractBits)));
}

Fixed::~Fixed() {}

std::ostream& operator<<(std::ostream& stream, const Fixed& src) {
    stream << src.toFloat();
    return (stream);
}

bool  Fixed::operator>(const Fixed& src) {
	return (getRawBits() > src._value);
}

bool  Fixed::operator<(const Fixed& src) {
	return (getRawBits() < src._value);
}

bool  Fixed::operator>=(const Fixed& src) {
	return (getRawBits() >= src._value);
}

bool  Fixed::operator<=(const Fixed& src) {
	return (getRawBits() <= src._value);
}

bool  Fixed::operator==(const Fixed& src) {
	return (getRawBits() == src._value);
}

bool  Fixed::operator!=(const Fixed& src) {
	return (getRawBits() != src._value);
}

Fixed& Fixed::operator=(const Fixed& src) {
    setRawBits(src._value);
    return (*this);
}

Fixed& Fixed::operator++() {
    ++_value;
    return (*this);
}

Fixed& Fixed::operator--() {
    --_value;
    return (*this);
}

Fixed Fixed::operator+(const Fixed& src) {
    Fixed tmp;
    tmp._value = getRawBits() + src._value;
    return (tmp);
}

Fixed Fixed::operator-(const Fixed& src) {
    Fixed tmp;
    tmp._value = getRawBits() - src._value;
    return (tmp);
}

Fixed Fixed::operator*(const Fixed& src) {
    Fixed tmp;
    tmp._value = (getRawBits() * src._value) >> _fractBits;
    return (tmp);
}

Fixed Fixed::operator/(const Fixed& src) {
    Fixed tmp;
    tmp._value = (getRawBits() >> _fractBits) / src._value;
    return (tmp);
}

Fixed Fixed::operator++(int) {
    Fixed tmp;
    tmp = *this;
    _value++;
    return (tmp);
}

Fixed Fixed::operator--(int) {
    Fixed tmp;
    tmp = *this;
    _value--;
    return (tmp);
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

Fixed& Fixed::min(Fixed& src1, Fixed& src2)
{
	if(src1.getRawBits() < src2.getRawBits())
		return(src1);
	else
		return(src2);
}

Fixed& Fixed::max(Fixed& src1, Fixed& src2)
{
	if(src1.getRawBits() > src2.getRawBits())
		return(src1);
	else
		return(src2);
}

const Fixed& Fixed::min(const Fixed& src1, const Fixed& src2)
{
	if(src1._value < src2._value)
		return(src1);
	else
		return(src2);
}

const Fixed& Fixed::max(const Fixed& src1, const Fixed& src2)
{
	if(src1._value > src2._value)
		return(src1);
	else
		return(src2);
}
