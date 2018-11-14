#include <iostream>
#include <sstream>

class Fixed {
	int _value;
	static const int _fractBits = 8;
public:
    Fixed();
	Fixed(int);
    Fixed(float);
    Fixed(const Fixed&);
	~Fixed();

    bool operator>(const Fixed&);
    bool operator<(const Fixed&);
    bool operator>=(const Fixed&);
    bool operator<=(const Fixed&);
    bool operator==(const Fixed&);
    bool operator!=(const Fixed&);

    Fixed operator+(const Fixed&);
    Fixed operator-(const Fixed&);
    Fixed operator*(const Fixed&);
    Fixed operator/(const Fixed&);
    Fixed operator++(int);
    Fixed operator--(int);
    Fixed& operator++();
    Fixed& operator--();
    Fixed& operator=(const Fixed&);

    int getRawBits();
    void setRawBits(int);
    int toInt() const;
    float toFloat() const;
	Fixed& min(Fixed&, Fixed&);
	Fixed& max(Fixed&, Fixed&);
	static const Fixed& min(const Fixed&, const Fixed&);
	static const Fixed& max(const Fixed&, const Fixed&);
};

std::ostream& operator <<(std::ostream&, const Fixed&);
